section .text

    default rel
    bits 64 
    
global _sdot

_sdot:
    xorps xmm1, xmm1 

    xor r9, r9 ; utilize as counter
    
    L1:
        cmp r9, rdi
        jge done
        
        movss xmm2, [rsi + r9*4]
        
        movss xmm3, [rdx + r9*4]
        
        mulss xmm2, xmm3
        
        addss xmm1, xmm2 ; add product to return
        
        inc r9
        jmp L1
        
    done:
        movss xmm0, xmm1 ; move xmm1 to xmm0 (return sdot)
        ret
