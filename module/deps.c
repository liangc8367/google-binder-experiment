#include <linux/fdtable.h>
#include <linux/sched.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>

#include "deps.h"

static void (*__fd_install_ptr)(struct files_struct *, unsigned int, struct file *) = __FD_INSTALL;
void __fd_install(struct files_struct *files, unsigned int fd, struct file *file)
{
	__fd_install_ptr(files, fd, file);
}

static int (*__alloc_fd_ptr)(struct files_struct *, unsigned , unsigned , unsigned ) = __ALLOC_FD;
int __alloc_fd(struct files_struct *files, unsigned start, unsigned end, unsigned flags)
{
	return __alloc_fd_ptr(files, start, end, flags);
}


static struct sighand_struct * (*__lock_task_sighand_ptr)(struct task_struct *tsk, unsigned long *flags) = __LOCK_TASK_SIGHAND;
struct sighand_struct *__lock_task_sighand(struct task_struct *tsk, unsigned long *flags)
{
	return __lock_task_sighand_ptr(tsk, flags);
}

static struct files_struct * (*get_files_struct_ptr)(struct task_struct *) = GET_FILES_STRUCT;
struct files_struct *get_files_struct(struct task_struct * files)
{
	return get_files_struct_ptr(files);
}

static struct vm_struct * (*get_vm_area_ptr)(unsigned long size, unsigned long flags)  = GET_VM_AREA;
struct vm_struct *get_vm_area(unsigned long size, unsigned long flags)
{
	return get_vm_area_ptr(size, flags);
}

static int (*can_nice_ptr)(const struct task_struct *p, const int nice) = CAN_NICE;
int can_nice(const struct task_struct *p, const int nice)
{
	return can_nice_ptr(p, nice);
}

static int (*__close_fd_ptr)(struct files_struct *files, unsigned int fd) = __CLOSE_FD;
int __close_fd(struct files_struct *files, unsigned int fd)
{
	return __close_fd_ptr(files, fd);
}

static void (*put_files_struct_ptr)(struct files_struct *fs) = PUT_FILES_STRUCT;
void put_files_struct(struct files_struct *fs)
{
	put_files_struct_ptr(fs);
}

static void (*unmap_kernel_range_ptr)(unsigned long addr, unsigned long size) = UNMAP_KERNEL_RANGE;
void unmap_kernel_range(unsigned long addr, unsigned long size)
{
	unmap_kernel_range_ptr(addr, size);
}

static void (*zap_page_range_ptr)(struct vm_area_struct *vma, unsigned long address, unsigned long size, struct zap_details * details) = ZAP_PAGE_RANGE;
void zap_page_range(struct vm_area_struct *vma, unsigned long address, unsigned long size, struct zap_details * details)
{
	zap_page_range_ptr(vma, address, size, details);
}

