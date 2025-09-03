# AWE-PREP

This repository contains all training and tutorials completed in preparation for the Offensive Security Exploitation Expert (OSEE) in conjunction with the Advanced Windows Exploitation (AWE / EXP-401) course.

I want to emphasize that this was a journey that happened over the course of years. When I set my sights on OSEE my goal was never to have the certification but rather to become an Exploit Developer. That said, what follows is a culmination of material I found relevant to the OSEE specifically.

This is not mentioned to deter you, rather to re-enforce direction. Should you stray from this path (e.g study ARM32, ARM64), you may find that it takes you longer to obtain this certification. I cannot emphasize enough focusing on x86 and x64 only (if possible) while embarking on this journey.

I do use affiliate links! So, if you purchase a book, please use them!

# Table of Contents

- [Prep Breakdown](#prep-breakdown)
    - [C Programming](#c-programming)
    - [Reverse Engineering and Binary Exploitation](#reverse-engineering-and-binary-exploitation)
    - [Path of Least Resistance](#path-of-least-resistance)
- [Post Breakdown](#post-breakdown)
- [Tooling](#tooling)
- [References]()

# Prep Breakdown

The following tables contain notes, courses, challenges, and tutorials taken in preparation for the AWE. Meaning this knowledge was gained *before* starting AWE.

## C Programming

Not exclusive to AWE, Exploit Developers often use the C programming language when writing kernel exploits. It's imperative that you know how to program in C and understand *types*, otherwise you will find reverse engineering extremely difficult.

Even if you are the best Golang/Rust developer in the world, I promise you that you will NEVER get the control that C gives you. You are working at a low level, if you're going to be using a high-level language it better be C/C++.

All books shown below were read from cover to cover, and all exercises were completed.

| Order | Type | Name | Links |
| --- | --- | --- | --- |
| 0x00 | Book | C The Absolute Beginners Guide	| [Amazon Purchase Link](https://www.amazon.com/Programming-Absolute-Beginners-Guide-3rd/dp/0789751984?tag=iluvu00-20) |
| 0x01 | Book | The C Programming Language | [Amazon Purchase Link](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628?tag=iluvu00-20) |
| 0x02 | Book | Effective C | [Amazon Purchase Link](https://www.amazon.com/Effective-2nd-Introduction-Professional-Programming/dp/1718504128?tag=iluvu00-20) |
| 0x03 | Open Source Training | Learn C++ | [LEARN C++ Online](https://www.learncpp.com/) |
| 0x04 | Open Source Training | Windows Kernel Programming (Programming LoL) | [My Notes](https://github.com/wetw0rk/AWE-PREP/tree/main/C%20Programming/0x04%20-%20Windows%20Kernel%20Programming%20(Programming%20LoL)) |
| 0x05 | Training | Windows Malware Techniques | [WINMAL Course (CodeMachine)](https://codemachine.com/trainings/winmal.html) |

## Reverse Engineering and Binary Exploitation

You will not be reverse engineering as much as you think throughout the AWE, this is not to say there is no reverse engineering. However, if you only focus on exploitation you will be severely limiting yourself. Without a basic understanding of reverse engineering the information will be significantly more difficult to digest. Always chase the knowledge these courses contain, and the certification will come.

Some quick notes on the these recommendations:

- ***Modern Binary Exploitation (MBE)***: I took this course BEFORE RET2 Systems released WarGames. If you take plan to pursue WarGames go ahead and skip MBE.
- ***RET2 Systems: The Fundamentals of Browser Exploitation***: Ultimately, I did find this course incredibly beneficial even outside of browsers. However, this course I would argue is more advanced than AWE in terms of subject matter so it's at your discretion whether you should pursue it. Due to my AWE start date I only got about 70% through the course.
- ***Corelan Heap Exploitation MasterClass***: If you fear Windows Heap, look no further. Although to be fully transparent I did not complete all challenges at the time of completion. However, shortly after completion I did discover multiple 0days in Broadcom products.
- ***The Ghidra Book***: I only read up to page 256 of this book in conjunction to WarGames. This book WAS NOT read from cover to cover.
- ***Evasion Techniques and Breaching Defenses (PEN-300)***: Although I never attempted the OSEP exam, I cannot deny that the way Offsec covers navigating the Windows API is excellent. If you can learn how to write programs using the Windows API without this course you can easily skip PEN-300. Keep in mind when I say program I mean process injections, memory management, etc.

With that, shown below is the table containing all subject matter that assisted me in gaining this knowledge.

| Order | Type | Name | Links |
| --- | --- | --- | --- |
| 0x00 | Training | SecurityTube Linux Assembly Expert (SLAE64) | [Updated Course Link](https://my.ine.com/CyberSecurity/courses/42f93b0f/x86_64-assembly-language-and-shellcoding-on-linux) |
| 0x01 | Open Source Training | Modern Binary Exploitation (MBE) | [MBE Course](https://github.com/RPISEC/MBE) <br><br> [MBE Notes](https://github.com/wetw0rk/MBE-NOTES) |
| 0x02 | Open Source Training | Corelan Exploit Writing Tutorials | [Exploit writing tutorial part 1 : Stack Based Overflows](https://www.corelan.be/index.php/2009/07/19/exploit-writing-tutorial-part-1-stack-based-overflows/) <br><br> [Exploit writing tutorial part 2 : Stack Based Overflows – jumping to shellcode](https://www.corelan.be/index.php/2009/07/23/writing-buffer-overflow-exploits-a-quick-and-basic-tutorial-part-2/) <br><br> [Exploit writing tutorial part 3 : SEH Based Exploits](https://www.corelan.be/index.php/2009/07/25/writing-buffer-overflow-exploits-a-quick-and-basic-tutorial-part-3-seh/) <br><br> [Exploit writing tutorial part 5 : How debugger modules & plugins can speed up basic exploit development](https://www.corelan.be/index.php/2009/09/05/exploit-writing-tutorial-part-5-how-debugger-modules-plugins-can-speed-up-basic-exploit-development/) <br><br> [Exploit writing tutorial part 7 : Unicode – from 0x00410041 to calc](https://www.corelan.be/index.php/2009/11/06/exploit-writing-tutorial-part-7-unicode-from-0x00410041-to-calc/) <br><br> [Exploit writing tutorial part 8 : Win32 Egg Hunting](https://www.corelan.be/index.php/2010/01/09/exploit-writing-tutorial-part-8-win32-egg-hunting/) <br><br> [QuickZip Stack BOF: A box of chocolates - part 1](https://www.offsec.com/blog/quickzip-stack-bof-0day-a-box-of-chocolates/) <br><br> [QuickZip Stack BOF: A box of chocolates – part 2](https://www.offsec.com/blog/quickzip-stack-bof-a-box-of-chocolates-part-2/) |
| 0x03 | Open Source Training | Vulnserver | [Vulnserver Repository](https://github.com/stephenbradshaw/vulnserver) |
| 0x04 | Training | Evasion Techniques and Breaching Defenses (PEN-300) | [PEN-300 Course Link](https://www.offsec.com/courses/pen-300/) | 
| 0x05 | Open Source Training | Basics of Windows shellcode writing | [Basics of Windows shellcode writing](https://idafchev.github.io/exploit/2017/09/26/writing_windows_shellcode.html) | 
| 0x06 | Training | Corelan HEAP Masterclass | [Corelan Heap exploitation masterclass](https://www.corelan-training.com/index.php/training/heap/) |
| 0x07 | Book | The Ghidra Book | [Amazon Purchase Link](https://www.amazon.com/Ghidra-Book-2nd-Definitive-Guide/dp/1718504683?tag=iluvu00-20) |
| 0x08 | Training | RET2 Systems Wargames | [RET2 Wargames](https://wargames.ret2.systems/) <br><br> [RET2 Wargames (Review)](https://www.linkedin.com/pulse/ret2-systems-wargames-review-milton-valencia-0udrf/) |
| 0x08 | Open Source Training | HackSysVulnerableDriver (HEVD) | [0xFF - HackSysExtremeVulnerableDriver (HEVD) Project](https://github.com/hacksysteam/HackSysExtremeVulnerableDriver) <br><br> [0x00 - Introduction to Windows Kernel Exploitation](https://wetw0rk.github.io/posts/0x00-introduction-to-windows-kernel-exploitation/) <br><br> [0x01 - Killing Windows Kernel Mitigations](https://wetw0rk.github.io/posts/0x01-killing-windows-kernel-mitigations/) <br><br> [0x02 - Introduction to Windows Kernel Use After Frees (UaFs)](https://wetw0rk.github.io/posts/0x02-introduction-to-windows-kernel-uafs/) <br><br> [0x03 - Approaching the Modern Windows Kernel Heap](https://wetw0rk.github.io/posts/0x03-approaching-the-modern-windows-kernel-heap/) <br><br> [0x04 - Introduction to Windows Kernel Write What Where Vulnerabilities](https://wetw0rk.github.io/posts/0x04-writing-what-where-in-the-kernel/) <br><br> [0x05 - Introduction to Windows Kernel Type Confusion Vulnerabilities](https://wetw0rk.github.io/posts/0x05-introduction-to-windows-kernel-type-confusion-vulnerabilities/) <br><br> [0x06 - Approaching Modern Windows Kernel Type Confusions](https://wetw0rk.github.io/posts/0x06-approaching-modern-windows-kernel-type-confusions/) <br><br> [0x07 - Introduction to Windows Kernel Race Conditions](https://wetw0rk.github.io/posts/0x07-introduction-to-windows-kernel-race-conditions/) <br><br> [0x08 - Modern Windows Kernel Race Conditions](https://wetw0rk.github.io/posts/0x08-modern-windows-kernel-race-conditions/) <br><br> [0x09 - Return of the Windows Kernel Stack Overflow](https://wetw0rk.github.io/posts/0x09-return-of-the-stack-overflow/) |
| 0x09 | Training | SANS 760 | [SANS 760 Course Information](https://www.sans.org/cyber-security-courses/advanced-exploit-development-penetration-testers) |
| 0x0A | Training | RET2 Systems: The Fundamentals of Browser Exploitation| [RET2 Purchase Link](https://ret2.io/trainings) |
| 0x0B | Training | Advanced Windows Exploitation (AWE) | [AWE Course Information](https://www.offsec.com/courses/exp-401/) |

# Post Breakdown

The following table contains notes, courses, challenges, and tutorials taken in preparation for the OSEE. Meaning this knowledge was gained *after* starting AWE.

Some of these will have *"todo links"* meaning that I have not uploaded the research yet... but rest assured I will!

| Order | Type | Name | Links |
| --- | --- | --- | --- |
| 0x00 | Open Source Training | Ezekiels Wheel (Hells Gate Analysis) | [My Analysis](https://wetw0rk.github.io/posts/ezekielswheel/ezekielswheel/) |
| 0x01 | Open Source Training | Reverse engineering the _SECURITY_DESCRIPTOR | [My Analysis (TODO)](https://wetw0rk.github.io/) <br><br> [Kernel ACE Edit Shellcode (Sickle Module)](https://github.com/wetw0rk/Sickle/blob/master/src/sickle/payloads/windows/x64/kernel_ace_edit.py) |
| 0x02 | Open Source Training | Leverage knowledge from RET2 to exploit CVE-2018-0617 | [My Analysis (TODO)](https://wetw0rk.github.io/) |
| 0x03 | Open Source Training | Writing shellcode with Sickle | [Tutorial (TODO)]() <br><br> [Sickle Project](https://github.com/wetw0rk/Sickle) |
| 0x04 | AWE | Study and understand JOP Gadgets | N/A |
| 0x05 | AWE | Create functions to leverage exploit primitives | N/A |
| 0x06 | AWE | Create high-level diagrams for each exploit within course | N/A |
| 0x07 | AWE | Complete as many extra-miles as possible before exam | N/A |
| 0x08 | AWE | Create a stable exploit for each section | N/A |
| 0x09 | AWE | Create a cheatsheet for all WinDbg commands | N/A |
| 0x0A | AWE | Create a cheetsheet for Ghidra | N/A |
| 0x0B | AWE | Create a cheatsheet for Sickle | N/A |
| 0x0C | AWE | Create a cheatsheet for Metasploit | N/A |

# Tooling

The AWE course uses a multitude of tools including IDA and from my understanding IDA Pro ***IS ALLOWED*** on the exam. However, I chose to use Ghidra instead... my reasoning for this can be summarized in three letters: *N - S - A*.

Aside from my choice of decompiler/disassembler I used the following tooling for the course and exam:

- [***Ghidra***](https://github.com/NationalSecurityAgency/ghidra): Throughout the entire course I used *Ghidra v11.1.2*, I went with this version from beginning to end. Upon completion of OSEE I upgraded to the latest version. To avoid any problems my recommendation is to use whatever version you install until you pass OSEE.
- [***Sickle***](https://github.com/wetw0rk/sickle): Shameless plug I did use my framework on the exam... although you can do without it I heavily recommend it. I plan on creating a tutorial on how I used it on the exam (without revealing any spoilers) but for now you can also check out my [Black Hat Arsenal Talk](https://youtu.be/FKcX-6jReAc?si=9_DYwyIDJQxeTnuR) where I demo some use cases. The exact version used on the exam was *v4.0.0-Beta*.
- [***Samba***](https://www.kali.org/tools/samba/): When performing debugging locally I used a local share for file transfers. This method WAS NOT used on the exam virtual machines since you will likely be reverting the remote machines... which would require re-authentication.
- [***xfreerdp***](https://www.kali.org/tools/freerdp3/): I did use this on the exam to "recreate" a share environment to that of what was used locally. The command used can be seen below.
    - xfreerdp /u:< username > /p:< password > /v:1.2.3.4 /size:1980x920 /drive:share,/< path to working directory >
- [***apache2***](https://www.kali.org/tools/apache2/): I'm not sure why but there were times my exploits did not fully function when using a python webserver - so I instead opted for apache2.
- [***Metasploit Framework***](https://www.kali.org/tools/metasploit-framework/): For the sake of simplicity, I decided to use meterpreter as my implant, however any C2 framework should work!
- [***Visual Studio***](https://visualstudio.microsoft.com/): Anything I needed to compile I used Visual Studio but ultimately you can use any compiler you are comfortable with.
- [***WinDbg***](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/): Notice how I did not say WinDbg Preview. I chose to only use Windbg Preview, when necessary (e.g: use time travel debugging), this was due to random bugs I would encounter. I found the WDK version to be a lot more stable.
- [***Python***](https://www.python.org/): For any userland exploitation I stuck with python3 unless the objective in a real-life scenario warranted the use of C. For example, any remote exploit is normally ran on your machine NOT the target machine. What runs on the target is the payload itself / exploitation buffer.
- [***C/C++***](https://en.wikipedia.org/wiki/C_(programming_language)): This was the language I used for local kernel exploits and anything intended to run on the target machine. I also stuck to "Windows" syntax. For example, instead of using an *unsigned long* type I would use a *DWORD* type.
- [***rp++***](https://github.com/0vercl0k/rp): This was the tool I used for ROP gadget hunting.

# References

Below are some references used throughout my journey. Please keep in mind that I try to include resources in each blog post as well. I like many others stand on the shoulders of giants.

I also wanted to thank God my lord and savior Jesus Christ, I feel incredible blessed to be where I am today.

```
https://codemachine.com/index.html
https://codemachine.com/trainings/winmal.html
https://connormcgarr.github.io/pte-overwrites/
https://connormcgarr.github.io/swimming-in-the-kernel-pool-part-1/
https://fluidattacks.com/blog/hevd-smep-bypass/
https://github.com/LordNoteworthy/windows-internals/blob/master/IRP%20Major%20Functions%20List.md
https://github.com/NationalSecurityAgency/ghidra
https://github.com/sam-b/windows_kernel_address_leaks/tree/3810bec445c0afaa4e23338241ba0359aea398d1
https://h0mbre.github.io/HEVD_Stackoverflow_SMEP_Bypass_64bit/#
https://idafchev.github.io/research/2023/06/30/Vulnerable_Driver_Part2.html
https://kristal-g.github.io/2021/02/07/HEVD_StackOverflowGS_Windows_10_RS5_x64.html
https://kristal-g.github.io/2021/02/20/HEVD_Type_Confusion_Windows_10_RS5_x64.html
https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/paged_code
https://m0uk4.gitbook.io/notebooks/mouka/windowsinternal/find-kernel-module-address-todo
https://media.blackhat.com/bh-dc-11/Mandt/BlackHat_DC_2011_Mandt_kernelpool-wp.pdf
https://microsoft.public.windbg.narkive.com/MamhR9YH/win7-and-kpcr
https://vulndev.io/2022/07/14/windows-kernel-exploitation-hevd-x64-use-after-free/
https://wafzsucks.medium.com/how-a-simple-k-typeconfusion-took-me-3-months-long-to-create-a-exploit-f643c94d445f
https://web.archive.org/web/20230602115237/https://www.alex-ionescu.com/kernel-heap-spraying-like-its-2015-swimming-in-the-big-kids-pool/
https://wumb0.in/finding-the-base-of-the-windows-kernel.html
https://www.corelan-training.com/
https://www.corelan.be/
https://www.coresecurity.com/sites/default/files/2020-06/Windows%20SMEP%20bypass%20U%20equals%20S_0.pdf
https://www.kn0sky.com/?p=194
https://www.offsec.com/courses/exp-401/
https://www.python.org/
https://www.sstic.org/media/SSTIC2020/SSTIC-actes/pool_overflow_exploitation_since_windows_10_19h1/SSTIC2020-Article-pool_overflow_exploitation_since_windows_10_19h1-bayet_fariello.pdf
https://www.vergiliusproject.com/
https://www.welivesecurity.com/2017/03/27/configure-windbg-kernel-debugging/
https://youtu.be/Ca3dAXDdoz8?si=oN_DsgyLz-Z4fVYL
https://youtu.be/FKcX-6jReAc?si=C9ww_wBdCA0vlSe3
```
