# DeepDiveSIMDProgrammingProject

For Deep Dive: SIMD programming project (CSC612M)

Name: Chen, Hannah L. / G01 


**ALL KERNELS ARE CHECKED WITH THE C VERSION ANSWER**

**C, x86-64, and SIMD YMM register are all run in 'x64 Release' in Visual Studio 2022**

**Sample .asm file command line setup information:**

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/2f1f0e43-c98c-4702-a349-89cd1cc02b80)


**I. Comparative Time Analysis of the Kernels (C, x86-64, SIMD YMM register, CUDA)**

  **Table showing the average execution time (30 runs) of different kernels under different vector sizes (in Microseconds):**
  
  
  
  a.) How many times faster?
  b.) Why is it faster?
  c.) Overheads (for CUDA)
**II. Screenshot of the program output with correctness check (C)**

  **a.) n = 2^20**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/92fb0751-cc31-42bd-ba18-10d64eac4052)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/19a623de-a595-41bc-866a-8a49bcd9aa46)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/1e4197b9-fb04-499c-9495-c3e65d6a6664)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/62b56107-218d-4d09-8065-737be35c971b)
  
  **b.) n = 2^24**

  
  
  c.) n = 2^26 _(Device cannot handle upto 2^28 or 2^30)_
  
**III. Screenshot of the program output including correctness check (x86-64)**

  **a.) n = 2^20**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/213e758f-adee-4d27-817a-97c890ab11a8)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/bd9acd63-6f1e-46dd-a8f3-4ec7ad03001d)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a8244592-abe5-4ffe-b99d-b56e928498a6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6ed7cce6-08d1-4d4c-a495-a6d55eb9f4ba)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/35968e1f-b40d-4cdd-8a58-126fdb63adc7)
  
  **b.) n = 2^24**
  
  c.) n = 2^26 _(Device cannot handle upto 2^28 or 2^30)_
  
**IV. Screenshot of the program output including correctness check (SIMD YMM register)**

  **a.) n = 2^20**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/11ebf477-8dd2-4f15-8a7e-f6b441429d6c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/65888565-2f84-47a3-934e-30ce39003a2c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6096088d-5e78-432b-88a8-423a4bbc1122)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/e5572922-1700-4e3e-92b0-afa3c515bb65)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/d448fd51-98e7-4e9c-9732-01e90907f411)
  
  **b.) n = 2^24**
  
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
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c05022c6-95d2-4684-a39b-bfe80acb9a85)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f48575ac-a543-4809-84bb-a77705464f55)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/728440f5-0b58-4cd6-b2ba-f785a06ae87e)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/3858ac99-d46e-4db6-a87d-8e5283070d34)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/bc0fe3ed-e7f1-47de-906b-888008d49417)


  **c.) n = 2^26** (Up to 2^26 for it to be the same as the other kernels - for more accurate comparative analysis)

  
  
