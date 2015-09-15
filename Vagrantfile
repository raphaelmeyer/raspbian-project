# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|

  config.vm.box = "ubuntu/vivid64"

  config.vm.synced_folder "./project", "/home/vagrant/project"

  config.vm.provider "virtualbox" do |vb|

    vb.memory = "2048"

    #vb.gui = true
    #vb.customize ["modifyvm", :id, "--vram", "64"]
    #vb.customize ["modifyvm", :id, "--accelerate3d", "on"]
  end

  #config.vm.provision "shell", inline: <<-SHELL
  #  sudo apt-get install -y lightdm lxde vim-gnome
  #SHELL

  config.vm.provision "shell", inline: <<-SHELL
    sudo apt-get update
    sudo apt-get install -y virtualbox-guest-dkms virtualbox-guest-utils virtualbox-guest-x11
    sudo apt-get install -y build-essential git cmake
  SHELL

  config.vm.provision "shell", privileged: false, inline: <<-SHELL
    mkdir rpi
    cd rpi
    git clone git://github.com/raspberrypi/tools.git
    cd ~/
    echo "" >> .bashrc
    echo "# Raspbian cross gcc" >> .bashrc
    echo "PATH=$PATH:$HOME/rpi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin" >> .bashrc
    echo "" >> .bashrc
  SHELL
end

