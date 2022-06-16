#!/bin/bash

echo "Hello ${USER^}"
currentdir=$(pwd)
echo "Your file backup from location is stared , Location : $currentdir"
tar -cf $currentdir "$(date +%d-%m-%Y_%H-%M-%S)".tar ~/* 2>/dev/null
echo "BACKUP DONE"
exit 0
