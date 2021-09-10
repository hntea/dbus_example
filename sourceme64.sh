#!/bin/bash
AARCH64=1
if [ x"${AARCH64}" != x""  ];  then
  echo "use aarch64 toolchain"
  .  /usr/local/oecore-x86_64/environment-setup-aarch64-oe-linux
else
  echo "use armv7 toolchain"
  .  /usr/local/oecore-x86_64/environment-setup-armv7ahf-neon-oe-linux-gnueabi
fi
