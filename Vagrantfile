VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
	config.vm.define "gpsim" do |gpsim|
	  gpsim.vm.box = "hashicorp/precise64"
	  gpsim.vm.box_url = "https://vagrantcloud.com/hashicorp/precise64/version/2/provider/virtualbox.box"

	  gpsim.vm.provision "shell", inline: "/vagrant/install.sh"
	end
end