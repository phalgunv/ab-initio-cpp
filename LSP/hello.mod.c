#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_DTRACE
# include "hello.sdtinfo.c"
#endif

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
#ifdef CONFIG_DTRACE
	.sdt_probes = _sdt_probes,
	.num_dtrace_probes = _sdt_probec,
#endif
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x52c13bce, "module_layout" },
	{ 0x27e1a049, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "C3DB3F776DA57EC5C632B11");
