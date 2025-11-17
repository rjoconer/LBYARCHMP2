section .text

    default rel
    bits 64 
    
global sdot

sdot:
    ;initialize xmm1
    mov rax, 0
    cvtsi2ss xmm1, rax
    
    xor r9, r9 ;utilize as counter
    
    L1:
        cmp r9, rcx ;rcx = n
        jge done
        
        ;convert value of a[r9] (rdx) to float
        movss xmm2, [rdx + r9*4]
        ;convert value of b[r9] (r8) to float
        movss xmm3, [r8 + r9*4]
        
        ;multiply element of a (in xmm2) to element of b (in xmm3)
        mulss xmm2, xmm3
        
        addss xmm1, xmm2 ;add product to return
        
        inc r9
        jmp L1
        
    done:
        movss xmm0, xmm1 ;move xmm1 to xmm0 (return sdot)
        ret