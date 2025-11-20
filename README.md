# LBYARCHMP2
**x86-to-C interface programming project**

---

### Project Specifications
> Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector A and vector B and place the result in sdot.

**Input:** Scalar variable n (integer) contains the length of the vector;  Vectors A and B are both single-precision float. Scalar sdot is a single-precision float.\
**Output:** store the result in memory location sdot.  Display the result for all versions of the kernel (i.e., C and  x86-64).

---

### Execution Analysis

> Click [here](https://drive.google.com/file/d/1X21pEA2bYtXxxb6HmAIf03dSfNG0qkf9/view?usp=sharing) to view sample run video.

|                         | C Kernel Average (after 20 runs) | x86-64 Average (after 20 runs) | Faster Run-Time + Time Difference |
|-------------------------|----------------------------------|--------------------------------|-----------------------------------|
| Testing for 2^20 inputs | 0.002850 seconds                 | 0.000600 seconds               | x86-64 by 0.00225 seconds         |
| Testing for 2^24 inputs | 0.047700 seconds                 | 0.010700 seconds               | x86-64 by 0.037 seconds           |
| Testing for 2^28 inputs | 0.651300 seconds                 | 0.157200 seconds               | x86-64 by 0.4941 seconds          |

From the table above, we can conclude that x86-64 runs faster than the C program. Since x86-64 Assembly is a low-level language, it is likely to have a faster execution time due to its closeness to the CPU's machine code and direct access/control over hardware. 

---

### Sample Program Output (with Correctness Check)
![Sample Program Output](/sdot_run.png)
