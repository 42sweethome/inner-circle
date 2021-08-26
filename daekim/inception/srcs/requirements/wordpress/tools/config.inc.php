<?php

declare(strict_types=1);


$cfg['blowfish_secret'] = 'mB6pa-XnbP4w];C[r/;z6h/x0iTT=7iw'; /* YOU MUST FILL IN THIS FOR COOKIE AUTH! */

$i = 0;

$i++;
/* Authentication type */
$cfg['Servers'][$i]['auth_type'] = 'cookie';
/* Server parameters */
$cfg['Servers'][$i]['host'] = 'localhost';
$cfg['Servers'][$i]['compress'] = false;
$cfg['Servers'][$i]['AllowNoPassword'] = false;



$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';
