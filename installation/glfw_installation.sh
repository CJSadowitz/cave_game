echo "Installing GLFW and GLM"
sudo apt install libglfw3-dev
sudo apt install libglm-dev
echo "Installing shader compiler"
wget https://storage.googleapis.com/shaderc/artifacts/prod/graphics_shader_compiler/shaderc/linux/continuous_gcc_release/476/20241207-090734/install.tgz
echo "Installed shader compiler"
tar xvzf install.tgz
sudo mv install/bin/glslc /usr/local/bin
echo "Moved shader compiler (glslc) to /user/local/bin"
rm -rf install/
echo "Removed install directory for shader compiler"
rm install.tgz
