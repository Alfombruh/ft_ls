## FT_LS

# Functions

<table>
    <tr>
        <th>Function</th>
        <th>Prototype</th>
        <th>Usage</th>
        <th>Return</th>
        <th>Used</th>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man3/opendir.3.html">opendir</a></td>
        <td><code>
            #include &lt;sys/types.h&gt; </br>
            #include &lt;dirent.h&gt;</br>
            DIR *opendir(const char *name);
        <code></td>
        <td>
            The opendir() function opens a directory stream corresponding to
            the directory name, and returns a pointer to the directory
            stream.  The stream is positioned at the first entry in the
            directory.
        </td>
        <td>
            The opendir() and fdopendir() functions return a pointer to the
            directory stream.  On error, NULL is returned, and errno is set
            to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man3/readdir.3.html">readdir</a></td>
        <td><code>
            #include &lt;dirent.h&gt;</br>
            struct dirent *readdir(DIR *dirp);
        <code></td>
        <td>
            The readdir() function returns a pointer to a dirent structure
            representing the next directory entry in the directory stream
            pointed to by dirp.  It returns NULL on reaching the end of the
            directory stream or if an error occurred.</br>
            <a href="https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html">struct dirent</a>
       </td>
        <td>
            On success, readdir() returns a pointer to a dirent structure.
            (This structure may be statically allocated; do not attempt to
            free(3) it.)
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man3/closedir.3.html">closedir</a></td>
        <td><code>
            #include &lt;dirent.h&gt;</br>
            #include &lt;sys/types.h&gt;</br>
            int closedir(DIR *dirp);
        <code></td>
        <td>
            The closedir() function closes the directory stream associated
            with dirp.  A successful call to closedir() also closes the
            underlying file descriptor associated with dirp.  The directory
            stream descriptor dirp is not available after this call.</br>
        </td>
        <td>
            The closedir() function returns 0 on success.  On error, -1 is
            returned, and errno is set to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man2/stat.2.html">stat</a></td>
        <td><code>
            #include &lt;sys/stat.h&gt;</br>
            int stat(const char *restrict pathname, struct stat *restrict statbuf);
        <code></td>
        <td>
            These functions return information about a file, in the buffer
            pointed to by statbuf.  No permissions are required on the file
            itself, but—in the case of stat(), fstatat(), and lstat()—execute
            (search) permission is required on all of the directories in
            pathname that lead to the file.</br>
            <a href="http://codewiki.wikidot.com/c:struct-stat">struct stat</a>
        </td>
        <td>
            On success, zero is returned.  On error, -1 is returned, and
            errno is set to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man2/stat.2.html">lstat</a></td>
        <td><code>
            #include &lt;sys/stat.h&gt;</br>
            int lstat(const char *restrict pathname, struct stat *restrict statbuf);
        <code></td>
        <td>
            lstat() is identical to stat(), except that if pathname is a
            symbolic link, then it returns information about the link itself,
            not the file that the link refers to.</br>
            <a href="http://codewiki.wikidot.com/c:struct-stat">struct stat</a>
       </td>
        <td>
            On success, zero is returned.  On error, -1 is returned, and
            errno is set to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man3/getpwuid.3p.html">getpwuid</a></td>
        <td><code>
            #include &lt;pwd.h&gt;</br>
            struct passwd *getpwuid(uid_t uid);
        <code></td>
        <td>
            The getpwuid() function shall search the user database for an
            entry with a matching uid.
       </td>
       <td>
            The getpwuid() function shall return a pointer to a struct passwd
            with the structure as defined in &lt;pwd.h&gt; with a matching entry if
            found. A null pointer shall be returned if the requested entry is
            not found, or an error occurs. If the requested entry was not
            found, errno shall not be changed. On error, errno shall be set
            to indicate the error.
       </td>
       </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man3/getgrgid.3p.html">getgrgid</a></td>
        <td><code>
            #include &lt;grp.h&gt;</br>
            struct group *getgrgid(gid_t gid);
        <code></td>
        <td>
            The getgrgid() function shall search the group database for an
            entry with a matching gid.
        </td>
        <td>
            Upon successful completion, getgrgid() shall return a pointer to
            a struct group with the structure defined in &lt;grp.h&gt; with a
            matching entry if one is found. The getgrgid() function shall
            return a null pointer if either the requested entry was not
            found, or an error occurred. If the requested entry was not
            found, errno shall not be changed. On error, errno shall be set
            to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man2/flistxattr.2.html">listxattr</a></td>
        <td><code>
            #include &lt;sys/xattr.h&gt;</br>
            ssize_t listxattr(const char *path, char *_Nullable list, size_t size);
        <code></td>
        <td>
             <h5>
                Extended attributes are name:value pairs associated with inodes
                (files, directories, symbolic links, etc.).  They are extensions
                to the normal attributes which are associated with all inodes in
                the system (i.e., the stat(2) data).  A complete overview of
                extended attributes concepts can be found in xattr(7).
            </h5>
            listxattr() retrieves the list of extended attribute names
            associated with the given path in the filesystem.  The retrieved
            list is placed in list, a caller-allocated buffer whose size (in
            bytes) is specified in the argument size.  The list is the set of
            (null-terminated) names, one after the other.  Names of extended
            attributes to which the calling process does not have access may
            be omitted from the list.  The length of the attribute name list
            is returned.
        </td>
        <td>
            On success, a nonnegative number is returned indicating the size
            of the extended attribute name list.  On failure, -1 is returned
            and errno is set to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man2/getxattr.2.html">getaxttr</a></td>
        <td><code>
            #include &lt;sys/xattr.h&gt;</br>
               ssize_t getxattr(const char *path, const char *name, void value[.size], size_t size);
        <code></td>
        <td>
            getxattr() retrieves the value of the extended attribute
            identified by name and associated with the given path in the
            filesystem.  The attribute value is placed in the buffer pointed
            to by value; size specifies the size of that buffer.  The return
            value of the call is the number of bytes placed in value.
        </td>
        <td>
            On success, these calls return a nonnegative value which is the
            size (in bytes) of the extended attribute value.  On failure, -1
            is returned and errno is set to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man2/time.2.html">time</a></td>
        <td><code>
            #include &lt;time.h&gt;</br>
            time_t time(time_t *_Nullable tloc);
        <code></td>
        <td>
            time() returns the time as the number of seconds since the Epoch,
            1970-01-01 00:00:00 +0000 (UTC).
        </td>
        <td>
            On success, the value of time in seconds since the Epoch is
            returned.  On error, ((time_t) -1) is returned, and errno is set
            to indicate the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man3/ctime.3.html">ctime</a></td>
        <td><code>
            #include &lt;time.h&gt;</br>
            char *ctime(const time_t *timep);
        <code></td>
        <td>
            The ctime(), gmtime(), and localtime() functions all take an
            argument of data type time_t, which represents calendar time.
            When interpreted as an absolute time value, it represents the
            number of seconds elapsed since the Epoch, 1970-01-01 00:00:00
            +0000 (UTC).
        </td>
        <td>
            On success, asctime() and ctime() return a pointer to a string.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
    <tr>
        <td><a href="https://man7.org/linux/man-pages/man2/readlink.2.html">readlink</a></td>
        <td><code>
            #include &lt;unistd.h&gt;</br>
                ssize_t readlink(const char *restrict pathname, char *restrict buf, size_t bufsiz);
        <code></td>
        <td>
            readlink() places the contents of the symbolic link pathname in
            the buffer buf, which has size bufsiz.  readlink() does not
            append a terminating null byte to buf.  It will (silently)
            truncate the contents (to a length of bufsiz characters), in case
            the buffer is too small to hold all of the contents.
        </td>
        <td>
            On success, these calls return the number of bytes placed in buf.
            (If the returned value equals bufsiz, then truncation may have
            occurred.)  On error, -1 is returned and errno is set to indicate
            the error.
        </td>
        <td> <input type="checkbox" checked></td>
    </tr>
</table>
