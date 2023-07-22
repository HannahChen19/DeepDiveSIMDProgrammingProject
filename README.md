# DeepDiveSIMDProgrammingProject
For Deep Dive: SIMD programming project (CSC612M)
Name: Chen, Hannah L. / G01 
**ALL KERNELS ARE CHECKED WITH THE C VERSION ANSWER ("EXPECTED SDOT" IS ALWAYS CODED IN C)**__
**I. Comparative Time Analysis of the Kernels (C, x86-64, SIMD YMM register, CUDA)**
  a.) How many times faster?
  b.) Why is it faster?
  c.) Overheads (for CUDA)
**II. Screenshot of the program output with correctness check (C)**
  a.) n = 2^20
  
  b.) n = 2^24
  
  c.) n = 2^26 _(Device cannot handle upto 2^28 or 2^30)_
  
**III. Screenshot of the program output including correctness check (x86-64)**
  a.) n = 2^20
  
  b.) n = 2^24
  
  c.) n = 2^26 _(Device cannot handle upto 2^28 or 2^30)_
  
**IV. Screenshot of the program output including correctness check (SIMD YMM register)**
  a.) n = 2^20
  
  b.) n = 2^24
  
  c.) n = 2^26 _(Device cannot handle upto 2^28 or 2^30)_
  
**V. Screenshot of the program output including correctness check (CUDA)**
  a.) n = 2^20
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/b179103e-afd0-4c1b-8a7f-31c2adaef8ce)

  b.) n = 2^24
  
  c.) n = 2^26 _(Up to 2^26 for it to be the same as the other kernels - for more accurate comparative analysis)_
  
