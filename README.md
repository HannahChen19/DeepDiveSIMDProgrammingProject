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

  **a.) n = 2^20**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/b179103e-afd0-4c1b-8a7f-31c2adaef8ce)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/4b6e9e63-c818-42c0-82a6-70972d3d88ec)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/464164ce-e822-4282-82f4-666a288441c5)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c04a4f71-562e-4f22-9949-dd1f2adc73ba)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f4803bdc-28e7-4f3d-aa06-638260faaaf9)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a5d6e0a3-f13f-4291-9181-8e1ab88d0ff5)

  **b.) n = 2^24**
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/0dda477c-abc4-4f61-9a89-9ec920c3f588)


  **c.) n = 2^26 _**(Up to 2^26 for it to be the same as the other kernels - for more accurate comparative analysis)_
  
