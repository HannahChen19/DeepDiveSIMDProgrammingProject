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

  Based on the execution times recorded in the table, it can be seen that for all vector sizes, the SIMD YMM register kernel is able to execute the fastest among all the kernels. This is because SIMD YMM register kernel allows processing of multiple data elements simultaneously, making it more efficient. In addition to this, another reason for the SIMD YMM register kernel to run the fast is because it is written in assembly language, which is a low-level language that can allow users to have more control over the hardware, thereby optimizing the kernel. It can also be seen from the table that the x86-64 kernel is the kernel that performs the second fastest. This is because although this type of kernel is also written in assembly language, it is using the XMM registers which is only 128-bit wide, causing it to hold lesser data compared to the SIMD YMM registers which are 256 bit wide and can hold more data and lead to faster performance. The C kernel, on the other hand, is slower than the x86-64 kernel. This is because C is a higher level language and it abstracts away some details of the hardware, causing overheads. Although the codes written in C kernel can be easier to understand, it is less efficient when compared to the kernels written using assembly languages.

  Despite having proper application of best implementations such as usage of memory prefetching, grid-stride loop, and memory advise, CUDA kernel running in the Google Colaboratory platform still has the longest execution time among the four kernels. Possible reasons for this may be because it is compiled and launched using NVIDIA GPU in Google colab, which can lead to more overheads in execution time, and also because Google Colab is using a shared GPU, which can lead to more limited resources and longer execution time. Another reason for this may also be due to CPUs typically having more limited memory compared to GPUs, which requires more data transfers and thereby resulting to longer execution times. Other reasons that contributes to the CUDA kernel having the longest execution time are the overheads when transferring data from CPU to GPU and from GPU to CPU.

  **b.) Analysis of Performance (including Analysis of CUDA vis-a-vis x86 SMID)**

  ![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/cf7bb2f1-a471-418c-a02f-fb6b2de692bb)

  The above image shows the computed rate of execution time increase for the different kernels under different vector sizes. As seen from the image, SIMD YMM register kernel have the greatest increase in execution time from vector size 2^20 to 2^24, which is around 15 times of increase, followed by the x86-64 kernel which is about 14 times of increase, then the CUDA kernel which is about 13 times of increase in execution time. For the vector size of 2^20 to 2^24, C kernel has the least increase in execution time, which is approximately 6 times only. For vector size from 2^24 to 2^26, the rate of increase in execution time are almost the same for all four kernels, which is approximately 3 times of its original execution time. The reason behind these differences in the rate of increase of execution time is because of the different techniques used by the different kernels in performing the task.
  
  The C kernel's rate of increase in execution time is not much affected by changes in vector sizes because it is not using any SIMD or parallelism instruction. Its execution time increase across the different vector sizes is more stable compared to the other kernels because of its lack of parallelism. However, it is also due to the lack of parallelism that as vector size increases, the C kernel will eventually become less efficient compared to the x86-64 kernels and SIMD YMM register kernels under the same vector size. For the x86-64 kernel, SIMD YMM register kernel, and CUDA kernel, the rate of execution time increase from vector size 2^20 to 2^24 is high but once it reaches 2^24 to 2^26, (even if putting into consideration the smaller vector size increase from 2^24 to 2^26 compare to the vector size increase from 2^20 to 2^24), there is still a huge decrease in the rate of execution time increase. The reason for this is because the SIMD YMM register kernel, x86-64 kernel, and CUDA kernel are using parallelism, which allows the processing of data in parallel, making it more and more efficient as vector size increases. Although all of the three kernels are using parallelism, SIMD YMM register kernel is the fastest as it is using 256 bit wide registers which can hold more data and it also allows processing of multiple data simultaneously. x86-64 kernel is the second fastest as it is only using 128 bit wide registers which holds lesser data. CUDA is the slowest due to the resource limitations and data transfer overheads in running using the Google Colaboratory platform's GPU. Another reason why once the vector size reaches 2^24 to 2^26 the rate of increase in execution time for all four kernels becomes almost the same is because the kernels are now reaching their limits of parallelism, causing the rate of increase in execution time to level off.

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/a045f995-a4a3-4ea0-95f7-bb44b29ba95f)

  The above image shows the rate of changes in the execution time of the different kernels. Analysis and comparison of the kernels' performances are as follows:

**CUDA kernel vs SIMD YMM register kernel**

  Based on the image above, it can be seen that the set of kernels with the greatest difference in terms of execution time is the SIMD YMM register kernel and CUDA kernel. The SIMD YMM register kernel is approximately 19 times faster than the CUDA kernel on vector size of 2^20, and approximately 18 times faster than the CUDA kernel on vector sizes 2^24 and 2^26. The reason for this is because the SIMD YMM register kernel is using 256 bit wide registers which can hold more data, and it is also capable of performing the same operation on multiple data items at the same time, which increases the execution speed. On the other hand, although the CUDA kernel in Google colab also applies parallelization techniques, it runs slower due to resource limitations and data transfer overheads (between CPU and GPU and vice versa) in Google colaboratory platform GPU.

**x86-64 kernel vs CUDA kernel**

  The x86-64 kernel is able to run approximately 11 times faster than the CUDA kernel for vector sizes 2^20, 2^24, and 2^26. The reason for this is because unlike the x86-64 kernel which do not use shared memory for communication, the CUDA kernel is using shared memory to communicate between threads, which can cause some bottlenecks on the performance. In addition to this, memory bandwidth and resource limitation also causes the CUDA kernel in Google colaboratory platform to run slower than the x86-64 kernel. Since the CUDA kernel is running in the Google colaboratory platform, shared GPUs are being used. This leads to performance degradation. Another reason is because the memory bandwidth of a GPU is typically higher than the memory bandwidth of a CPU which can lead to more data transfer overheads. This causes the CUDA kernel to perform slower since the x86-64 do not have this bottleneck.

**C kernel vs SIMD YMM register kernel**

  For the C kernel and SIMD YMM register kernel, the SIMD YMM register kernel was able to perform approximately 6 times faster than the C kernel on vector size of 2^20, and approximately 2 times faster on vector sizes 2^24 and 2^26. The reason for this is because the SIMD YMM register kernel is able to use SIMD instructions which allows operating of multiple data elements simultaneously to reduce the execution time needed. On the other hand, C kernel do not use SIMD instructions and it operates on one data element at a time, making it less efficient. Another reason is because SIMD instructions can be pipelined and processed in parallel by the CPU, leading to better instruction-level parallelism and improved performance compared to the serial execution of code in C kernel.
  
**C kernel vs CUDA kernel**

  The C kernel is able to execute at approximately 3 times faster than the CUDA kernel on vector size of 2^20, approximately 6 times faster on vector size of 2^24, and approximately 7 times faster on vector size of 2^26. The reason for this is because CUDA kernel is being run in the Google colaboratory platform's GPU, which uses shared resources causing resource limitations that can degrade the performance. Another reason is because of the data transfer overheads (between CPU and GPU and vice versa) in the CUDA kernel. If the program requires frequent data transfer between CPU and GPU and vice versa, the CUDA kernel will require more execution time. This causes the C kernel to run faster despite it not using parallelism.

**C kernel vs x86-64 kernel**

  For C kernel and x86-64 kernel, x86-64 kernel was able to run approximately 3 times faster than the C kernel for vector size of 2^20 and approximately 1 time faster for the vector sizes of 2^24 and 2^26. The reason is because x86-64 kernel is written in assembly language, which has less abstractions and better optimizes the kernel. On the other hand, C kernel is using high-level language, which is easier to understand but can be less efficient. Another reason is because x86-64 assembly language can allow direct access to specific CPU instructions that cannot be done with C. This can cotribute to improvements in the kernel's performance especially when dealing with complex tasks.

**x86-64 kernel vs SIMD YMM register kernel**

  This pair of kernel has the lowest difference in terms of execution time. For all vector sizes of 2^20, 2^24, and 2^26, the SIMD YMM register is able to run 1 time faster than the x86-64 kernel. The reason for this is because the SIMD YMM register kernel is using 256 bit wide registers and is capable of handling more data compared to the x86-64 kernel that only uses 128 bit wide registers. This allows the SIMD YMM register to execute faster than the x86-64 kernel. 

![image](https://github.com/HannahChen19/DeepDiveSIMDProgrammingProject/assets/132733094/483e6ad7-881d-4ea1-a212-bf1b3c4d5492)

**CUDA Overheads and Pagefaults**
  
  The above image shows the overheads and page fault results of the CUDA kernel. After applying the best CUDA implementation practices (grid-stride loop, memory prefetching, memory advice), the kernel was able to achieve the data transfer time showed in the above image, with the transferring of data from device to host to be faster than from host to device. The reason for this is because from host to device, the operation is more bandwidth limited as the GPU's memory is often faster than the CPU's memory. Another reason is because when transferring data from host to device, the operation is often more complex as it requires the host to first copy the data into the GPU's memory, and the GPU also needs to allocate space for the data. For this project, no page faults were present for both CPU and GPU.
    
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
