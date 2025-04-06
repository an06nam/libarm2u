# Setting
ARG DEBIAN_VERSION=12.10-slim
ARG TOOLCHAINS=/opt/toolchains

# Set debian 12.10 as the base image
FROM debian:${DEBIAN_VERSION}

ARG DEBIAN_VERSION
ARG TOOLCHAINS

# Set default shell during Docker image build to bash
SHELL ["/bin/bash", "-c"]

# Set non-interactive frontend for apt-get to skip any user confirmations
ENV DEBIAN_FRONTEND=noninteractive

# install dependencies
RUN apt update && apt upgrade -y && \
	apt install -y \
	build-essential \
	git \
	curl \
	wget \
	gcc-arm-none-eabi \
	cmake \
	make \
	ninja-build \
	libnewlib-arm-none-eabi \
	vim \
 	clangd-19 \
	clang-format-19 \
	clang-tidy-19 \
	openssh-server \
 	ca-certificates \
 	--no-install-suggests --no-install-recommends

# Create symlink
RUN ln -s $(which clang-format-19) /usr/bin/clang-format && \
	ln -s $(which clang-tidy-19) /usr/bin/clang-tidy && \
 	ln -s $(which clangd-19) /usr/bin/clangd

# Set up directories
RUN mkdir -p /workspace/ && \
	mkdir -p /opt/toolchains

# Install LLVM Arm toolchain
RUN cd /opt/toolchains && \
	wget -c https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm/releases/download/release-19.1.5/LLVM-ET-Arm-19.1.5-Linux-x86_64.tar.xz && \
	tar xvf *.tar.xz && \
	mv LLVM-ET-Arm-19.1.5-Linux-x86_64 llvm-arm-19 && \
	rm *.tar.xz && \
	echo 'export PATH=$PATH:/opt/toolchains/llvm-arm-19/bin' >> /root/.bashrc

########################################################################
# Create user [ for a better user experiece at least for me ]
# RUN useradd -ms /bin/bash user && \
#	usermod -aG sudo user && \
#	echo 'user:user' | chpasswd

# USER user
# RUN cd $HOME && \
#	wget -c https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm/releases/download/release-19.1.5/LLVM-ET-Arm-19.1.5-Linux-x86_64.tar.xz && \
#	tar xvf *.tar.xz && \
#	mv LLVM-ET-Arm-19.1.5-Linux-x86_64 llvm-arm-19 && \
#	rm *.tar.xz && \
#	echo 'export PATH=$PATH:$HOME/llvm-arm-19/bin' >> $HOME/.bashrc && \
#	mkdir Workspace

# USER root
# Clean up stale packages
###########################################################################

RUN apt-get clean -y && \
	apt-get autoremove --purge -y && \
	rm -rf /var/lib/apt/lists/*

# Set up sshd working directory
RUN mkdir -p /var/run/sshd && \
    chmod 0755 /var/run/sshd

# Expose SSH port
EXPOSE 22

# Set Root passworkd
RUN echo "root:root" | chpasswd

WORKDIR /workspace
