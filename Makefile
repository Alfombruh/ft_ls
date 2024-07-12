NAME = ft_ls
CC = clang
CFLAGS = -Werror -Wextra -Wall
FILES = srcs/main \
		srcs/parse/parseArguments \
		srcs/debug/prints \

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(addsuffix .o,$(FILES))
#font Larry 3D https://patorjk.com//software/taag/#p=display&f=Larry%203D&t=Type%20Something%20
define HEADER

 ____    ______         __       ____       
/\  _`\ /\__  _\       /\ \     /\  _`\     
\ \ \L\_\/_/\ \/       \ \ \    \ \,\L\_\   
 \ \  _\/  \ \ \        \ \ \  __\/_\__ \   
  \ \ \/    \ \ \        \ \ \L\ \ /\ \L\ \ 
   \ \_\     \ \_\        \ \____/ \ `\____\ 
    \/_/      \/_/  _______\/___/   \/_____/ 
                   /\______\                
                   \/______/                

endef
export HEADER

all: $(NAME)

%.o : %.c
	@$(CC) -I includes/ $(CFLAGS) -c $^ -o $@ >/dev/null

$(NAME): $(OBJS)
	@printf "\e[32mObjects Compiled✅\e[0m\n"
	@printf "\e[32mCompiling libraries...⏳\e[0m\n"
	@$(MAKE) -C srcs/libft >/dev/null
	@$(CC) $(CFLAGS) $(OBJS) srcs/libft/libft.a -o $(NAME) >/dev/null
	@printf "\e[32m$$HEADER\e[0m\n"

sanitize: 
	@printf "\e[32mAdding Sanitize to CFLAGS\e[0m\n"
	$(eval CFLAGS+= -fsanitize=address -g3)

sani: sanitize all

clean:
	@$(MAKE) clean -C srcs/libft >/dev/null
	@rm -rf *.dSYM >/dev/null
	@rm -rf $(OBJS) >/dev/null
	@printf "\e[31m*.o=>🗑️\e[0m\n"

fclean: clean
	@$(MAKE) fclean -C srcs/libft >/dev/null
	@rm -rf $(NAME) >/dev/null
	@printf "\e[31m(ft_ls && srcs/libft/libft.a)=>🗑️\e[0m\n"

re: fclean all

##--DOCKER THINGS--##
docker:
	@printf "\e[91m🐋resetting docker🐋\e[0m\n"
	@docker system prune -fa 2>/dev/null
	@-docker volume rm $(docker volume ls -q)  2>/dev/null
	@-docker rm -f $$(docker ps -aq) 2>/dev/null
	@-docker rmi $$(docker images -aq) 2>/dev/null

image:
	docker build -t valgrind .

valgrind: image
	docker run -it -v $$PWD:/tmp valgrind

enter:
	docker exec -it bash valgring


.PHONY: all sanitize sani clean fclean valgrind image docker enter