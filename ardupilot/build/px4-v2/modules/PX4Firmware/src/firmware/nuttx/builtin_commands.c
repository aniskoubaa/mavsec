/* builtin command list - automatically generated, do not edit */
#include <nuttx/config.h>
#include <nuttx/binfmt/builtin.h>
#include <nuttx/config.h>
extern int adc_main(int argc, char *argv[]);
extern int tone_alarm_main(int argc, char *argv[]);
extern int fmu_main(int argc, char *argv[]);
extern int bl_update_main(int argc, char *argv[]);
extern int mixer_main(int argc, char *argv[]);
extern int perf_main(int argc, char *argv[]);
extern int reboot_main(int argc, char *argv[]);
extern int top_main(int argc, char *argv[]);
extern int nshterm_main(int argc, char *argv[]);
extern int mtd_main(int argc, char *argv[]);
extern int ver_main(int argc, char *argv[]);
extern int usb_connected_main(int argc, char *argv[]);
extern int otp_main(int argc, char *argv[]);
extern int uorb_main(int argc, char *argv[]);
extern int pwm_input_main(int argc, char *argv[]);
extern int px4io_main(int argc, char *argv[]);
extern int sercon_main(int argc, char *argv[]);
extern int ArduPilot_main(int argc, char *argv[]);

const struct builtin_s g_builtins[] = {
	{"adc", SCHED_PRIORITY_DEFAULT, 1024, adc_main},
	{"tone_alarm", SCHED_PRIORITY_DEFAULT, 1024, tone_alarm_main},
	{"fmu", SCHED_PRIORITY_DEFAULT, 1200, fmu_main},
	{"bl_update", SCHED_PRIORITY_DEFAULT, 4096, bl_update_main},
	{"mixer", SCHED_PRIORITY_DEFAULT, 4096, mixer_main},
	{"perf", SCHED_PRIORITY_DEFAULT, 1800, perf_main},
	{"reboot", SCHED_PRIORITY_DEFAULT, 800, reboot_main},
	{"top", SCHED_PRIORITY_DEFAULT, 1700, top_main},
	{"nshterm", SCHED_PRIORITY_DEFAULT-30, 1500, nshterm_main},
	{"mtd", SCHED_PRIORITY_DEFAULT, 1024, mtd_main},
	{"ver", SCHED_PRIORITY_DEFAULT, 1024, ver_main},
	{"usb_connected", SCHED_PRIORITY_DEFAULT, 1024, usb_connected_main},
	{"otp", SCHED_PRIORITY_DEFAULT, 1800, otp_main},
	{"uorb", SCHED_PRIORITY_DEFAULT, 2048, uorb_main},
	{"pwm_input", SCHED_PRIORITY_DEFAULT, 1024, pwm_input_main},
	{"px4io", SCHED_PRIORITY_DEFAULT, 1800, px4io_main},
	{"sercon", SCHED_PRIORITY_DEFAULT, 2048, sercon_main},
	{"ArduPilot", SCHED_PRIORITY_DEFAULT, 4096, ArduPilot_main},

	{NULL, 0, 0, NULL}
};
const int g_builtin_count = 18;
