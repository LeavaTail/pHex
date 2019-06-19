#!/bin/sh

./phex nothing
if [ $? -gt 0 ]; then
	return 0
fi

return 1
