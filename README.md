# ImGui test app

- [ImGui CI](https://github.com/ocornut/imgui/blob/master/.github/workflows/build.yml)

# Deps
```sh
sudo apt-get update
sudo apt-get install -y make cmake libglfw3-dev libsdl2-dev gcc-multilib g++-multilib libfreetype6-dev
```

# Build
```sh
mkdir build
cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=~/GitBinary/imgui
make -j 15
make install
```

# Run
```sh
cd ~/GitBinary/imgui/bin
./ImGuiTest
```