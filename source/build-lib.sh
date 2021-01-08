# 基于cmake 3.12.4版本构建

mkdir build
mkdir static
mkdir shared

cd build
# 默认先构建静态库
cmake -DCMAKE_INSTALL_PREFIX=../static ../
make
make install

# 重新构建动态库
cmake -DCMAKE_INSTALL_PREFIX=../shared -DBUILD_SHARED_LIBS=ON .
make
make install
