cmake_minimum_required(VERSION 3.15)
project(CustomGameSDK)

set(CMAKE_CXX_STANDARD 20)

# Kütüphaneyi tanımla
add_library(sdk
    src/sdk.cpp
    # src/events.cpp  <-- Bu dosyalar klasöründe yoksa hata verir, varsa kalsın
    # src/plugin_loader.cpp
)

target_include_directories(sdk PUBLIC include)

# --- EKLEMEN GEREKEN KISIM ---
# main.cpp'yi çalıştırılabilir bir dosya olarak ekle
add_executable(MyGame main.cpp)

# main.cpp'nin sdk kütüphanesini kullanmasını sağla
target_link_libraries(MyGame PRIVATE sdk)
