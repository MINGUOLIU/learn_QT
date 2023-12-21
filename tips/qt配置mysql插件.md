由于我使用的qt6.6没有自带的mysql驱动需要自行通过源码编译

驱动源码目录在D:/Qt/6.3.0/Src/qtbase/src/plugins/sqldrivers下

打开powershell终端，分别输入以下命令
> cd D:/Qt/6.3.0/Src/qtbase/src/plugins/sqldrivers
>
> mkdir build   //创建一个目录用于cmake构建
> cd build
> D:\Qt\6.6.1\mingw_64\bin\qt-cmake -G Ninja .. -DMySQL_INCLUDE_DIR="D:\vclib\mysql\include" -DMySQL_LIBRARY="D:\vclib\mysql\lib\libmysql.lib" 
-DCMAKE_INSTALL_PREFIX="D:\Qt\6.6.1\mingw_64"
>
> cmake --build .
> 
> cmaek --install .
> 
> 
最后在将libmysql.dll添加到D:\Qt\6.6.1\mingw_64\bin就完成了，此方法的好处可以直接install驱动不用拖拽文件。 

路径最好都不要带空格， mysql存在空格可以将相关的include、lib两个目录复制到其他路径。同时要添加g++和gcc的环境变量，添加qt自带的mingw编译器到环境变量中。



官方给出的实列代码
<code>
mkdir build-sqldrivers
cd build-sqldrivers
qt-cmake -G Ninja <qt_installation_path>\Src\qtbase\src\plugins\sqldrivers -DCMAKE_INSTALL_PREFIX=<qt_installation_path>\<platform> -DMySQL_INCLUDE_DIR="C:\mysql-8.0.22-winx64\include" -DMySQL_LIBRARY="C:\mysql-8.0.22-winx64\lib\libmysql.lib"
cmake --build .
cmake --install .
</code>

详情见官方文档 https://doc.qt.io/qt-6/sql-driver.htm

