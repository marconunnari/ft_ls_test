#!/usr/bin/env bash

make -C ft_ls >/dev/null
cp ft_ls/ft_ls ls.out
./ls.out $@
rm ls.out
