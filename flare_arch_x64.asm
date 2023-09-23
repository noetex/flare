.intel_syntax noprefix
.global

get_cpu_vendor_name:
	mov rdi, rcx
	xor eax, eax
	cpuid
	mov dword ptr[rdi], ebx
	mov dword ptr[rdi + 4], edx
	mov dword ptr[rdi + 8], ecx
	ret

get_cpu_features_amd:
	mov eax, 1
	cpuid
	mov [esi], ebx
	mov [esi + 4], edx
	ret

extended_features_exist:
	mov eax, 0x80
	cpuid
	cmp eax, 0x80
	seta al
	movzx eax, al
	ret
