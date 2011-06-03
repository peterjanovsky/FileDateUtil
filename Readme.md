#v0.1

### file date properties

     use these libraries to make the following file properties accessible within your Java source

          mtime: time of last modification
          ctime: time of last status change
          atime: time of last access

     the C source utilizes the stat() POSIX library functions and is accessible via JNI from the Java source

### building

     run the following build commands

     1. javac -sourcepath src -classpath classes src/com/pjanof/cache/utilities/FileDateUtil.java -d classes
     2. javah -jni -classpath classes -o src/com/pjanof/cache/utilities/FileDateUtil.h com.pjanof.cache.utilities.FileDateUtil
     3. gcc -m64 -fPIC -I/usr/lib/jvm/java/include -I/usr/lib/jvm/java/include/linux -c src/com/pjanof/cache/utilities/FileDateUtil.c -o classes/com/pjanof/cache/utilities/FileDateUtil.o
     4. gcc -m64 -shared -I/usr/lib/jvm/java/include -I/usr/lib/jvm/java/include/linux -W1,-soname,classes/com/pjanof/cache/utilities/libFileDateUtil.so -o classes/com/pjanof/cache/utilities/libFileDateUtil.so classes/com/pjanof/cache/utilities/FileDateUtil.o
     5. cp classes/com/pjanof/cache/utilities/libFileDateUtil.so /usr/lib

## requires

     JNI
