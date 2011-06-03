#v0.1

### file date properties

     mtime: time of last modification
     ctime: time of last status change
     atime: time of last access

### building

     javac -sourcepath src -classpath classes src/com/pjanof/cache/utilities/FileDateUtil.java -d classes
     /root/jdk1.6.0_22/bin/javah -jni -classpath classes -o src/com/pjanof/cache/utilities/FileDateUtil.h com.pjanof.cache.utilities.FileDateUtil
     gcc -m64 -fPIC -I/usr/lib/jvm/java/include -I/usr/lib/jvm/java/include/linux -c src/com/pjanof/cache/utilities/FileDateUtil.c -o classes/com/pjanof/cache/utilities/FileDateUtil.o
     gcc -m64 -shared -I/usr/lib/jvm/java/include -I/usr/lib/jvm/java/include/linux -W1,-soname,classes/com/pjanof/cache/utilities/libFileDateUtil.so -o classes/com/pjanof/cache/utilities/libFileDateUtil.so classes/com/pjanof/cache/utilities/FileDateUtil.o
     cp classes/com/pjanof/cache/utilities/libFileDateUtil.so /usr/lib

## requires

     JNI
