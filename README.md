# DeepDiveSIMDProgrammingProject

For Deep Dive: SIMD programming project (CSC612M)

Name: Chen, Hannah L. / G01 


**ALL KERNELS ARE CHECKED WITH THE C VERSION ANSWER**

**ALL KERNELS RUN UP TO A VECTOR SIZE OF 2^26 ONLY DUE TO DEVICE LIMITATIONS (CUDA ALSO RUNS UP TO 2^26 VECTOR SIZE ONLY FOR THE PURPOSE OF MORE ACCURATE COMPARATIVE ANALYSIS WITH THE OTHER KERNELS)**

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
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f6116ee8-b4dc-4b78-b537-a20c36034258)
  
  **b.) n = 2^24**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/2d40c9bb-6f35-4f17-9231-7aba72e1ccc3)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/b25e5bbd-bbb1-498a-b2b3-b27974ac9f39)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c607c7f1-a646-4584-a1a0-d741719dbc04)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7e61765c-05bf-4708-8140-e0c7e177b583)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/2550ba8f-df92-4c16-91fb-41f640eb572a)
  
  **c.) n = 2^26 (Device cannot handle upto 2^28 or 2^30)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/adbf7731-4098-44a8-b280-06ca82b67c3e)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/e5deca36-a1fe-48a0-9193-a8a8d63a983a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/578f8ca7-054f-482f-a36d-a195a2d66bb6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c5fe711b-b452-4d5b-851d-0ae209d0206a)
  
**III. Screenshot of the program output including correctness check (x86-64)**

  **a.) n = 2^20**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/213e758f-adee-4d27-817a-97c890ab11a8)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/bd9acd63-6f1e-46dd-a8f3-4ec7ad03001d)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a8244592-abe5-4ffe-b99d-b56e928498a6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6ed7cce6-08d1-4d4c-a495-a6d55eb9f4ba)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/1295b5dc-2bc0-4bdd-9303-76876ec49335)
  
  **b.) n = 2^24**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c21b5906-88a2-4727-924f-c783f201c60a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7b44f49b-4a23-45cf-91fa-02202363dc35)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/d16b9b25-3601-4415-8477-e9e7d724e0fd)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/032b6d24-9402-44df-8d66-fcd676d5385b)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/1c955339-d77b-4238-b23d-a456060fa388)
  
  **c.) n = 2^26 (Device cannot handle upto 2^28 or 2^30)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/8aa0c4a3-ab7d-45c7-a3cf-a50ac32b17e1)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/bb113423-2c43-46e2-993c-2ae16059949a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a4a92d50-5a3f-4df7-8253-6e27d78b035d)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/60c2d638-05d6-4884-9d37-a2bf4e3130f4)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f15903ef-3894-4d04-b5a8-44f62896c7b3)
      
**IV. Screenshot of the program output including correctness check (SIMD YMM register)**

  **a.) n = 2^20**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/11ebf477-8dd2-4f15-8a7e-f6b441429d6c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/65888565-2f84-47a3-934e-30ce39003a2c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6096088d-5e78-432b-88a8-423a4bbc1122)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/e5572922-1700-4e3e-92b0-afa3c515bb65)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/d4b57c95-c72e-42ee-ada7-492a6c10cd7b)
  
  **b.) n = 2^24**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/64836e29-3f56-433a-8995-bba6562c94d9)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6a842e17-da86-4f33-b603-7b90097ec396)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ae6e398c-689e-4660-8fac-eff5eaf187d0)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f688f2d7-95c5-4354-a5bc-cd445350be77)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7cff159e-bd08-4791-aeb8-578fd60f3942)
  
  **c.) n = 2^26 (Device cannot handle upto 2^28 or 2^30)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/23dbb41c-df49-4d4f-b4ee-3edcfc533e96)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ab771320-a5c5-4210-9f0a-27565a69af72)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/068ab4e6-c6ad-44c4-a065-a20236b4cc7a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/395f133c-e693-4ff5-b549-e27d217a69fe)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/27e22c71-6d57-4ff6-9651-31b68cc8ff3e)
    
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

  
  
