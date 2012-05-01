<?php

system('make clean');
system('cd lib/libsass && make && cd ../..');
system('phpize');
system('./configure');
system('make');