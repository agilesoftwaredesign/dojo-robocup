# Build
Build dependency https://github.com/Corvusoft/restbed

    git clone https://github.com/corvusoft/restbed.git
    mkdir restbed/build
    cd restbed
    git submodule init
    git submodule update dependency/asio
    cd build
    cmake -DBUILD_SSL=NO -DBUILD_TESTS=NO ..
    cmake --build . --target install

Build application (back in ```cpp``` folder):

    cmake .
    cmake --build .

# Run
Run with

    ./server

Test with script in ```../test/``` folder.