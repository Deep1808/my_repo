#!/bin/bash

read -p "Enter your name: " fname
read -p "Enter your surname: " sname
read -N 4 -p "What is your extension: " ext 
read -s -p "Please enter your ACCESS CODE: " acode

echo $fname $sname $ext $acode >> extension.csv 
