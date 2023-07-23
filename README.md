# DeepDiveSIMDProgrammingProject

For Deep Dive: SIMD programming project (CSC612M)

Name: Chen, Hannah L. / G01 


**ALL KERNELS ARE CHECKED WITH THE C VERSION ANSWER (EXPECTED SDOT FOR CUDA PROGRAM IS CODED IN C)**

**ALL KERNELS RUN UP TO A VECTOR SIZE OF 2^26 ONLY DUE TO DEVICE LIMITATIONS (CUDA ALSO RUNS UP TO 2^26 VECTOR SIZE ONLY FOR THE PURPOSE OF MORE ACCURATE COMPARATIVE ANALYSIS WITH THE OTHER KERNELS)**

**C, x86-64, and SIMD YMM register are all run in 'x64 Release' in Visual Studio 2022**

**Sample .asm file command line setup information:**

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/2f1f0e43-c98c-4702-a349-89cd1cc02b80)

**LINK TO COLAB CUDA PROGRAM:** https://colab.research.google.com/drive/1V-BPCtgHmwzt7vNL3rOqbQ8g47iHu2xQ?usp=sharing


**I. Comparative Execution Time and the Analysis of the Performance of Kernels (C, x86-64, SIMD YMM register, CUDA)**

  **a.) Comparison of the average execution time (30 runs) of different kernels under different vector sizes (in Microseconds):**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/8cb084b3-a395-4d7f-bd83-f79c8d197f7b)

  The above table shows the execution time of each kernel in microseconds. For the CUDA kernel, data transfer time and page fault results were also included. All of the required kernels (C, x86-64, SIMD YMM register, and CUDA) were run 30 times under vector sizes 2^20, 2^24, and 2^26, and the average execution times were recorded. The highest vector size run is until 2^26 only due to device limitations. As shown in the table, the kernel with the fastest execution time is the SIMD YMM register kernel, followed by the C kernel, then the x86-64 kernel, with the CUDA kernel having the longest execution time. 

  Based on the execution times recorded in the table, it can be seen that in vector size 2^20, the C kernel was able to execute the fastest among all the available kernels. However, as the vector size increases, SIMD YMM register kernel starts to execute faster than all other kernels. This is because SIMD YMM register kernel allows performing of multiple data elements in parallel, making it more efficient when processing large vector sizes. Another reason may be due to the fact that all kernels have some overheads in it and when the vector size is small (2^20), the overheads of the other kernels (x86-64, SIMD YMM register) may be significant compared to its actual execution time, thereby outweighting its benefit. Because of that, in the case of the project, at smaller vector sizes, a C kernel becomes more efficient. 

  It can also be seen from the table that the x86-64 kernel is having longer execution time compared to the C kernel, which is actually a new finding for me as I was initially expecting the x86-64 kernel to run faster than the C kernel. Possible reasons for this will be due to the complexity of the x86-64 assembly code, which may lead to increased instruction count and overhead compared to the higher-level abstractions provided by C. Another reason may be due to the large vector size that exceed the CPU's cache capacity, thereby leading to more frequent cache misses for the x86-64 kernel, causing a longer execution time. 

  Despite having proper application of memory prefetching, usage of grid-stride loop and memory advise, CUDA in Google Colaboratory platform still has the longest execution time among the four kernels. Possible reasons for this may be because it is compiled and launched in GPU, which can lead to more overheads in execution time, and also because Google Colab is using a shared GPU, which can lead to longer execution time. Another reason for this may also be due to GPUs having more limited memory compared to CPU, which requires more data transfers and thereby resulting to longer execution times.

  **b.) Analysis of Performance**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7add8fb5-1dff-4a05-8daf-7e65e732d7f6)

  The above image shows the computed rate of increase for the different kernels under different vector sizes. 

  
      a.) How many times faster?

  
      b.) Why is it faster?

  
      c.) Overheads (for CUDA)

  **c.) Analysis of CUDA vis-a-vis x86 SIMD**

  
    
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
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/397943f9-ec78-46eb-907d-4ae8565ccc4b)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/80d7ac19-bb43-43f4-9497-ce68d5db9dc1)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/8a98202e-b1bb-46f6-887c-a1d39cf61cc3)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/285a4a8f-e9aa-441b-b6da-270f87036376)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/79fa9c18-ebc8-4061-a26b-0c963b545901)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/d407194c-ef25-43b1-b724-0a47803e35a6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/b21e3b43-5e71-422e-8d2b-8844c8eece43)
  
  **b.) n = 2^24**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/1ce3fcc5-d94e-4976-8bbc-adee17dd0e6d)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/24e460cc-01c2-4e31-97e6-02f8418dd8f2)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/3b35eb12-4541-4cb1-8072-87134310758c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/4af855ff-c8c0-4812-a122-522715eb8f6f)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/501ff40a-7b7c-424b-bd14-e1a663ad3e68)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/5b636888-b74c-4cc4-b2e7-592cab3fb4db)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/9649dff3-e334-490e-bf89-668e6afdd5cb)

  **c.) n = 2^26** (Up to 2^26 for it to be the same as the other kernels - for more accurate comparative analysis)

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c6bdc8aa-03c4-4761-bbc6-0baba11f17b8)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ac917699-fd1d-4e70-bc3f-83af0d7eb41b)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7b52df85-9df3-4d74-8870-4a76c3871bd3)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ebc014b2-f334-4bf9-94ef-54c47a072010)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/9c7e09bd-7dfe-44fc-a731-39534e17bbe6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/1f7e12aa-5f52-4630-b58d-b85e6ac61587)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/03ac6db7-0161-44e7-aed6-80a8376b2dc9)
