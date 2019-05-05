# Compiling Kernel with BFQ I/O scheduling algorithm support

### 0# Check your current I/O scheduling algorithms available
```
cat /sys/block/sdX/queue/scheduler
```

> Replace the *_X_* with your properly device

If your kernel doesn't has support for `bfq`, the output should be something like this:
```
noop deadline [cfq]
```

This means that you have 3 algorithms and the `cfq` is the selected one.

### 1# Download official kernel image
```
sudo apt source linux-image-$(uname -r)
cd linux-x.x.x
```

### 2# Download the `bfq` patches from [here](https://bfq.teambelgium.net/bfq/patches/)

### 3# Incorpore the patches to kernel
```
patch -p1 < 0001-...
patch -p1 < 0002-...
patch -p1 < 0003-...
```

> One `patch` command for each patch

### 4# Prepare your system to compile the Kernel
```
sudo apt update
apt-get install -y build-essential libncurses5-dev gcc libssl-dev grub2 bc
```

### 5# Set the configurations with `menuconfig`
```
sudo menuconfig
```

Then navigate to _IO Schedulers_.

The next step is to check _BFQ I/O Scheduler_ and set it as the default on _Default I/O scheduler_ option.

Finally, save it and exit.


### 6# Compile the Kernel
```
make deb-pkg
```

> It will create a few _.deb_ files in the parent directory that represent your custom kernel version

### 7# Install the new Kernel
```
sudo dpkg -i linux-*.deb
```

## Useful links
- https://bfq.teambelgium.net/
- https://www.youtube.com/watch?v=ZeNbS0rzpoY
- https://www.linode.com/docs/tools-reference/custom-kernels-distros/custom-compiled-kernel-debian-ubuntu/
