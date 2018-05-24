/**
    file: arch/riscv/include/asm/processor.h
*/

///#define __riscv_muldiv
#define barrier() __asm__ __volatile__("": : :"memory")

static inline void cpu_relax(void)
{
#ifdef __riscv_muldiv
	int dummy;
	/* In lieu of a halt instruction, induce a long-latency stall. */
	__asm__ __volatile__ ("div %0, %0, zero" : "=r" (dummy));
#endif
	barrier();
}

int main()
{
    cpu_relax();

    return 0;
}
