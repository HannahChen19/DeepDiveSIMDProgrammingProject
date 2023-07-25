# DeepDiveSIMDProgrammingProject

For Deep Dive: SIMD programming project (CSC612M)

Name: Chen, Hannah L. / G01 


**ALL KERNELS ARE CHECKED WITH THE C VERSION ANSWER (EXPECTED SDOT FOR CUDA PROGRAM IS CODED IN C ALSO)**

**ALL KERNELS RUN UP TO A VECTOR SIZE OF 2^26 ONLY DUE TO DEVICE LIMITATIONS (CUDA ALSO RUNS UP TO 2^26 VECTOR SIZE ONLY FOR THE PURPOSE OF MORE ACCURATE COMPARATIVE ANALYSIS WITH THE OTHER KERNELS)**

**C, x86-64, and SIMD YMM register kernels are all run in 'x64 Release' configuration in Visual Studio 2022**

**Sample .asm file command line setup information:**

**NOTE: For the running of SIMD YMM register kernel, if on the first run, the result shows wrong, just ctrl + save the asmfunc1.asm file (without changing anything in it), then rerun. (This happened once on my laptop, but works correctly upon resaving without having to change anything in any of the codes)**

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/2f1f0e43-c98c-4702-a349-89cd1cc02b80)

**LINK TO COLAB CUDA PROGRAM:** https://colab.research.google.com/drive/1V-BPCtgHmwzt7vNL3rOqbQ8g47iHu2xQ?usp=sharing


**I. Comparative Execution Time and the Analysis of the Performance of Kernels (C, x86-64, SIMD YMM register, CUDA)**

  **a.) Comparison of the average execution time (30 runs) of different kernels under different vector sizes (in Microseconds):**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/230c1354-2707-4be4-83b0-a4a2dc376000)

  The above table shows the execution time of each kernel in microseconds. For the CUDA kernel, data transfer time and page fault results were also included. All of the required kernels (C, x86-64, SIMD YMM register, and CUDA) were run 30 times under vector sizes 2^20, 2^24, and 2^26, and the average execution times were recorded. The highest vector size run is until 2^26 only due to device limitations. As shown in the table, the kernel with the fastest execution time is the SIMD YMM register kernel, followed by the x86-64 kernel, then the C kernel, with the CUDA kernel having the longest execution time. 

  Based on the execution times recorded in the table, it can be seen that in vector size 2^20, the C kernel was able to execute the fastest among all the available kernels. However, as the vector size increases, SIMD YMM register kernel starts to execute faster than all other kernels. This is because SIMD YMM register kernel allows performing of multiple data elements in parallel, making it more efficient when processing large vector sizes. The reason of C kernel being the fastest kernel in vector size 2^20 may be due to the fact that all kernels have some overheads in it and when the vector size is small (2^20), the overheads of the other kernels (x86-64, SIMD YMM register) may be significant compared to its actual execution time, thereby outweighting its benefit. Because of that, in the case of the project, at smaller vector sizes, a C kernel is more efficient. 

  It can also be seen from the table that the x86-64 kernel is having longer execution time compared to the C kernel, which is actually a new finding for me as I was initially expecting the x86-64 kernel to run faster than the C kernel. Possible reasons for this will be due to the complexity of the x86-64 assembly code, which may lead to increased instruction count and overhead compared to the higher-level abstractions provided by C. Another reason may be due to the large vector size that exceed the CPU's cache capacity, thereby leading to more frequent cache misses for the x86-64 kernel, causing a longer execution time. 

  Despite having proper application of best practices such as usage memory prefetching, grid-stride loop, and memory advise, CUDA in the Google Colaboratory platform still has the longest execution time among the four kernels. Possible reasons for this may be because it is compiled and launched in GPU, which can lead to more overheads in execution time, and also because Google Colab is using a shared GPU, which can lead to longer execution time. Another reason for this may also be due to GPUs having more limited memory compared to CPU, which requires more data transfers and thereby resulting to longer execution times.

  **b.) Analysis of Performance (including Analysis of CUDA vis-a-vis x86 SMID)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/cf7bb2f1-a471-418c-a02f-fb6b2de692bb)

  The above image shows the computed rate of increase for the different kernels under different vector sizes. As seen from the image, C and CUDA kernels have the greatest rate of increase in execution time from vector size 2^20 to 2^24, which is around 13 times of increase in execution time. Under the same vector size, x86-64 kernel increased by 6 times, and SIMD YMM register kernel increased by approximately 8 times of the execution time. On the other hand, for the vector size from 2^24 to 2^26, the increase is approximately 3 times of the execution time for all kernels. 

  For smaller vector sizes, C and CUDA have more significant execution time increases because when vector sizes are small, vectorizations for x86-64 kernels and SIMD YMM register kernels may not have significant impacts yet, leading to lesser overhead changes and less significant performance impacts as vector size changes. The C and CUDA kernels' execution time increased larger compared to the other two kernels for smaller vector sizes because they are more sensitive to the cache size. For small vector sizes, when using C and CUDA kernels, the entire vector can fit in the cache and data can be access more quickly, resulting to faster execution time. However, as the vector size increases to 2^24, the execution time will be significantly increased as not all vectors can now fit in the cache and it will require more time to access the data. As the vector size continues to increase and becomes even larger, the cache size is not as much of a factor anymore because the entire vector will now not fit in the cache regardless of the size of the vector. This is why the rate of increase in the execution time from vector size 2^24 to 2^26 are almost the same for all of the kernels.

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7b4969b6-4da4-427d-a90a-74cc6c630596)

  The above image shows the rate of changes in the execution time of the different kernels. Analysis and comparison of the kernels' performances are as follows:

**C kernel vs CUDA kernel**
  
  Based on the table, it can be seen that the greatest execution time increase is from the C to CUDA kernel, where C kernel is able to execute approximately 17 times faster for vector sizes of 2^20 and 2^24, and approximately 19 times faster for vector size 2^26 compare to that of the CUDA kernel. This is because the CUDA kernel is running in the Google colaboratory platform which uses shared GPU, resulting to limited memory and more overheads for data transfer, making it to take longer to complete the execution process.

**CUDA kernel vs SIMD YMM register kernel**

  The second set of kernel with the greatest changes in execution time is the CUDA kernel and SIMD YMM register kernel. As seen in the image above, the SIMD YMM register kernel was able to run approximately 13 times faster in vector size of 2^20, and approximately 20 times faster in vector size of 2^24 and 2^26 compared to CUDA kernel. This is because SIMD YMM register kernel is capable of allowing the processor to process multiple elements at the same time, making it to complete the tasks faster.

**C kernel vs x86-64 kernel**

  For C and x86-64 kernel, C was able to run approximately 3 times faster for vector size of 2^20 and approximately 1 time faster for the vector sizes of 2^24 and 2^26 compared to the x86-64 kernel. This is an interesting finding as I was initially expecting the x86-64 kernel to run faster than the C kernel. The reason behind this may be due to the complexity of the x86-64 assembly code which leads to more overhead time compared to the C kernel. 

**C kernel vs SIMD YMM register kernel**

  For the C and SIMD YMM register kernel, the C kernel was able to run approximately 1 time faster than the SIMD YMM register kernel for vector size of 2^20. However, for vector sizes of 2^24 and 2^26, the SIMD YMM register kernel was able to run approximately 0.87 to 0.93 times faster than the C kernel. This is because when the vector size is still small, the capability of SIMD YMM register to process multiple data elements at the same time is still not that beneficial and the overhead of the kernel still outweights it's benefit, making it slower than the C kernel.

**x86-64 kernel vs SIMD YMM register kernel**

  For the x86-64 and SIMD YMM register kernel, the SIMD YMM register kernel runs at an approximate of 0.35 to 0.47 times faster than the x86-64 kernel due to its capability of processing multiple elements at the same time which can help in improving the amount of execution time.

**x86-64 kernel vs CUDA kernel**

  For the x86-64 and CUDA kernel, the x86-64 kernel was able to run at an approximate of 4 times faster for vector size 2^20, and approximately 9 times faster for vector sizes 2^24 and 2^26. The reason for this is because the CUDA kernel is being run at the Google colab platform, which uses shared GPU and has limited memory, making it to have more overheads and resulting to a longer execution time.

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/483e6ad7-881d-4ea1-a212-bf1b3c4d5492)

**CUDA Overheads and Pagefaults**
  
  The above image shows the overheads and page fault results of the CUDA kernel. After applying the best CUDA implementation practices (grid-stride loop, memory prefetching, memory advice), the kernel was able to achieve the data transfer time shown in the above image, with the transferring of data from device to host to be faster than from host to device. The reason for this is because from host to device, the operation is more bandwidth limited as the GPU's memory is often faster than the CPU's memory. Another reason is because when transferring data from host to device, the operation is often more complex as it requires the host to first copy the data into the GPU's memory, and the GPU also needs to allocate space for the data. For this project, no page faults were present for both CPU and GPU.
    
**II. Screenshots of the program outputs with correctness check (C)**

  **a.) n = 2^20**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/92fb0751-cc31-42bd-ba18-10d64eac4052)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/19a623de-a595-41bc-866a-8a49bcd9aa46)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/1e4197b9-fb04-499c-9495-c3e65d6a6664)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/b2b1c13c-a406-4003-93d8-8d5a82915272)
  
  **b.) n = 2^24**
  
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/2d40c9bb-6f35-4f17-9231-7aba72e1ccc3)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/b25e5bbd-bbb1-498a-b2b3-b27974ac9f39)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c607c7f1-a646-4584-a1a0-d741719dbc04)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7e61765c-05bf-4708-8140-e0c7e177b583)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f719f9c5-eab7-465b-8fa3-2286d4090567)
  
  **c.) n = 2^26 (Device cannot handle upto 2^28 or 2^30)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/adbf7731-4098-44a8-b280-06ca82b67c3e)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/e5deca36-a1fe-48a0-9193-a8a8d63a983a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/578f8ca7-054f-482f-a36d-a195a2d66bb6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/83961766-160c-4f41-a899-a53bab854069)
  
**III. Screenshot of the program output including correctness check (x86-64)**

  **a.) n = 2^20**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/213e758f-adee-4d27-817a-97c890ab11a8)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/bd9acd63-6f1e-46dd-a8f3-4ec7ad03001d)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a8244592-abe5-4ffe-b99d-b56e928498a6)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6ed7cce6-08d1-4d4c-a495-a6d55eb9f4ba)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6a982931-cd16-49a9-9b30-8e61f27b09db)
  
  **b.) n = 2^24**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/c21b5906-88a2-4727-924f-c783f201c60a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/7b44f49b-4a23-45cf-91fa-02202363dc35)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/d16b9b25-3601-4415-8477-e9e7d724e0fd)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/032b6d24-9402-44df-8d66-fcd676d5385b)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ca649f6d-5afd-40b7-9737-47c854db1a99)
  
  **c.) n = 2^26 (Device cannot handle upto 2^28 or 2^30)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/8aa0c4a3-ab7d-45c7-a3cf-a50ac32b17e1)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/bb113423-2c43-46e2-993c-2ae16059949a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a4a92d50-5a3f-4df7-8253-6e27d78b035d)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/60c2d638-05d6-4884-9d37-a2bf4e3130f4)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/9b219f7c-fbc2-414d-8ebe-86f8f3c47a13)
      
**IV. Screenshot of the program output including correctness check (SIMD YMM register)**

  **a.) n = 2^20**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/11ebf477-8dd2-4f15-8a7e-f6b441429d6c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/65888565-2f84-47a3-934e-30ce39003a2c)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6096088d-5e78-432b-88a8-423a4bbc1122)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/e5572922-1700-4e3e-92b0-afa3c515bb65)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/82fa6e0c-36c1-40da-84e5-373f2a595d29)
  
  **b.) n = 2^24**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/64836e29-3f56-433a-8995-bba6562c94d9)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/6a842e17-da86-4f33-b603-7b90097ec396)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ae6e398c-689e-4660-8fac-eff5eaf187d0)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/f688f2d7-95c5-4354-a5bc-cd445350be77)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a1b93213-352b-4097-8218-be9ebd6ec860)
  
  **c.) n = 2^26 (Device cannot handle upto 2^28 or 2^30)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/23dbb41c-df49-4d4f-b4ee-3edcfc533e96)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/ab771320-a5c5-4210-9f0a-27565a69af72)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/068ab4e6-c6ad-44c4-a065-a20236b4cc7a)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/395f133c-e693-4ff5-b549-e27d217a69fe)
  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/9c052353-73c4-4589-9ebe-c64acf9c635e)
    
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
