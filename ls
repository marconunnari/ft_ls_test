#!/usr/bin/env bash

if make -C ft_ls >/dev/null
then
	cp ft_ls/ft_ls ls.out
	./ls.out $@
else
	echo "Error compiling"
fi
