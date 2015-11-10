#!/bin/sh

SYMS="__fd_install __alloc_fd __lock_task_sighand get_files_struct get_vm_area can_nice __close_fd put_files_struct unmap_kernel_range zap_page_range"

for sym in $SYMS; do 
	addr=`cat /proc/kallsyms | grep -Ee '^[0-9a-f]+ T '$sym'$' | sed -e 's/\s.*$//g'`
	if [ a$addr = 'a' ]; then
		echo "Error: can't find symbol $sym"
		exit 1
	fi

	name=`echo $sym | tr '[:lower:]' '[:upper:]'`
	echo "#define $name\t(void *)0x$addr"
done
