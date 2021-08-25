echo "\033[47;35m--Setting for docker--\033[0m\n"


apt-get remove docker docker-engine docker.io containerd runc

apt-get update
apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -apt-key fingerprint 0EBFCD88

add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

apt-get update && sudo apt-get install docker-ce docker-ce-cli containerd.iodocker run hello-world

apt-get install docker-compose

usermod -aG docker ${USER}

echo  "\033[44;33m@@@It's set up for docker@@@\033[0m\n\n"
