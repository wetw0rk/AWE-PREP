# AWE-PREP

This repository contains all training and tutorials completed in preparation for the Offensive Security Exploitation Expert (OSEE) in conjunction with the Advanced Windows Exploitation (AWE / EXP-401) course.

This repo will likely contain custom code by me and various courses.

# Table of Contents

- [Prep Breakdown](#prep-breakdown)
    - [C Programming](#c-programming)
    - [Reverse Engineering and Binary Exploitation]()
- [Post Breakdown](#post-breakdown)
- [Tooling]()

# Prep Breakdown

The following table contains notes, courses, challenges, and tutorials taken in preparation for the AWE. Meaning this knowledge was gained *before* starting AWE.

## C Programming

Not exclusive to AWE, Exploit Developers often use the C programming language when writing kernel exploits. It's imperative that you know how to program in C and understand *types*, otherwise you will find reverse engineering extremely difficult.

Even if you are the best Golang/Rust developer in the world, I promise you that you will NEVER get the control that C gives you. You are working at a low level, if you're going to be using a high level language it better be C/C++.

Both of these books were read from cover to cover and all exercises were completed.

| Order | Type | Name |
| --- | --- | --- |
| 0 | Book | [The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628) |
| 1 | Book | [Effective C by Robert C. Seacord](https://nostarch.com/effective-c-2nd-edition) |

## Reverse Engineering and Binary Exploitation

You will not be reverse engineering as much as you think throughout the AWE, this is not to say there is no reverse engineering. However, If you only focus on exploitation you will be severly limiting yourself. Don't be the person that chases a certification, be the person that seeks the knowledge it contains.

To get the most out of the course I cannot emphasize enough exercising the art of reverse engineering in addition to binary exploitation. Notably when reading *The Ghidra Book* I only read up to page 265 in conjunction with *RET2 WarGames*. In addition I started AWE during *RET2's Browser Training* so I got about 70% through it.

Shown below is the table containing all subject matter that assisted me in gaining this knowledge.

***NOTE: IF YOU TAKE RET2 WARGAMES YOU CAN SKIP MODERN BINARY EXPLOITATION***

| Order | Type | Name |
| --- | --- | --- |
| 0 | Open Source Training | [Modern Binary Exploitation (Course)](https://github.com/RPISEC/MBE) <br> [Modern Binary Exploitation (My Notes)](https://github.com/wetw0rk/MBE-NOTES) |
| 1 | Book | [The Ghidra Book: The Definitive Guide by Chris Eagle and Kara Nance](https://nostarch.com/ghidra-book-2e) |
| 1 | Training | [RET2 Wargames](https://wargames.ret2.systems/) <br> [RET2 Wargames (Review)](https://www.linkedin.com/pulse/ret2-systems-wargames-review-milton-valencia-0udrf/) |
| 2 | Open Source Training | [0xFF - HackSysExtremeVulnerableDriver (HEVD)](https://github.com/hacksysteam/HackSysExtremeVulnerableDriver) <br> [0x00 - Introduction to Windows Kernel Exploitation](https://wetw0rk.github.io/posts/0x00-introduction-to-windows-kernel-exploitation/) <br> [0x01 - Killing Windows Kernel Mitigations](https://wetw0rk.github.io/posts/0x01-killing-windows-kernel-mitigations/) <br> [0x02 - Introduction to Windows Kernel Use After Frees (UaFs)](https://wetw0rk.github.io/posts/0x02-introduction-to-windows-kernel-uafs/) <br> [0x03 - Approaching the Modern Windows Kernel Heap](https://wetw0rk.github.io/posts/0x03-approaching-the-modern-windows-kernel-heap/) <br> [0x04 - Introduction to Windows Kernel Write What Where Vulnerabilities](https://wetw0rk.github.io/posts/0x04-writing-what-where-in-the-kernel/) <br> [0x05 - Introduction to Windows Kernel Type Confusion Vulnerabilities](https://wetw0rk.github.io/posts/0x05-introduction-to-windows-kernel-type-confusion-vulnerabilities/) <br> [0x06 - Approaching Modern Windows Kernel Type Confusions](https://wetw0rk.github.io/posts/0x06-approaching-modern-windows-kernel-type-confusions/) <br> [0x07 - Introduction to Windows Kernel Race Conditions](https://wetw0rk.github.io/posts/0x07-introduction-to-windows-kernel-race-conditions/) <br> [0x08 - Modern Windows Kernel Race Conditions](https://wetw0rk.github.io/posts/0x08-modern-windows-kernel-race-conditions/) <br> [0x09 - Return of the Windows Kernel Stack Overflow](https://wetw0rk.github.io/posts/0x09-return-of-the-stack-overflow/) |
| 3 | Training | [The Fundamentals of Browser Exploitation by RET2](https://ret2.io/trainings) |

Ultimately I did find *The Fundementals of Browser Exploitation* incredibly beneficial even outside of browsers. However, this course I would argue is more advanced than AWE in terms of subject matter so it's at your descrection weather or not you should pursue it.

# Post Breakdown