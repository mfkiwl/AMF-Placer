![DocumentationFlow](https://github.com/zslwyuan/AMF-Placer/actions/workflows/main.yml/badge.svg) ![CMakeFlow](https://github.com/zslwyuan/AMF-Placer/actions/workflows/cmake.yml/badge.svg)  <img src="https://raw.githubusercontent.com/zslwyuan/AMF-Placer/cloc_code/cloc_code.svg" alt="LoCCode" title="LoCCode" height="18" /> 
  <img src="https://raw.githubusercontent.com/zslwyuan/AMF-Placer/cloc_code/cloc_comment.svg" alt="LoCComment" title="LoCComment" height="18" /> 


<a class="el" href="https://github.com/zslwyuan/AMF-Placer">Access The GitHub Project</a>


**Introduction**

AMF-Placer is an open-source analytical mixed-size FPGA placer supporting heterogeneous resources (LUT/FF/LUTRAM/MUX/CARRY/DSP/BRAM...) on FPGA, with an interface to
Xilinx Vivado. To enable the performance optimization of application mapping on modern field-programmable gate arrays (FPGAs),
certain critical path portions of the designs might be prearranged into many multi-cell macros during synthesis.
These movable macros with constraints of shape and resources lead to challenging mixed-size placement for FPGA
designs which cannot be addressed by previous works of analytical placers and has been resolved by AMF-Placer. To speed up the convergence and improve the quality of the placement, AMF-Placer is equipped with
a series of new techniques for wirelength optimization, cell spreading, packing, and legalization. Based on a set
of the latest large open-source benchmarks from various domains for Xilinx Ultrascale FPGAs, experimental results
indicate that AMF-Placer can improve HPWL by 20.4%-89.3% and reduce runtime by 8.0%-84.2%, compared to the
baseline. Furthermore, utilizing the parallelism of the proposed algorithms, with 8 threads, the placement procedure
can be accelerated by 2.41x on average. 

<center>
<img src="OpenPiton_converge.gif" alt="Convergence (OpenPiton)" title="Convergence (OpenPiton)" width="100" />    <img src="MiniMap2_converge.gif" alt="Convergence (MiniMap2)" title="Convergence (MiniMap2)" width="100" />   <img src="optimsoc_converge.gif" alt="Convergence (OptimSoC)" title="Convergence (OptimSoC)" width="100" />    <img src="MemN2N_converge.gif" alt="Convergence (MemN2N)" title="Convergence (MemN2N)" width="100" /> 
</center>

**License**

This project is developed by [Reconfiguration Computing Systems Lab](https://eeweiz.home.ece.ust.hk/), Hong Kong University of Science and Technology (HKUST). Tingyuan Liang (tliang@connect.ust.hk), Gengjie Chen (chen_gengjie.hotmail.com), Jieru Zhao (zhao-jieru.sjtu.edu.cn), Sharad Sinha (sharad@iitgoa.ac.in) and Wei Zhang (eeweiz@ust.hk) are the major contributors of this project.

For non-commercial usage of this open-source project, users should comply the Apache License attached in the root directory.
For commercial usage of this open-source project, users must contact project supervisor (Wei ZHANG, eeweiz@ust.hk) for authorization.

**Documentation Hierarchy**

* [Basic Project Introduction](@ref _1_intro): motivation, features and some experimental results.
* [Get Started](@ref _2_getStarted): guideline to use the placer for your work.
* [Benchmarks and Experimental Results](@ref _3_benchmarkInfo): practical benchmarks for evaluation and some experimental results at current stages.
* [Publications](@ref _4_publication): some papers which are the fundamental parts of this project.
* [Implementation Explanation](@ref _5_explanation): the concrete explaination of the major novel contributions, the function modules and the placement procedure.
* [Existing Problems When Exporting To Vivado](@ref _7_portabilityToVivadoProblem): the concrete explaination of some of our known problems when interacting with Vivado.
* [Some Failure Lessons](@ref _8_someFailureLesson): Some of our previous failure lessons might be helpful for people who also want to develop their own physical synthesis flow.


**Motivations**

1. Just reinvent the wheel for fun, try to build a complete flow and reproduce/improve some state-of-art techniques in the latest papers.
2. Resolve some existing constraints in some previous works and consider more practical situations, like FPGA mixed-size placement with a series of optimization from the perspectives of timing, clocking, routability-aware and parallelism.
3. A beginner-friendly placement framework with clear hierarchy and detailed Doxygen-based documentation. We hope that it can lower the overhead for people who are also interested in this research area.
4. Currently, this framework is under development and it is still far from our goals and the practical demands, but we are happy to share our progress in this GitHub repository. If you have any questions/problems/suggestions, please contact feel free to contact us (Tingyuan LIANG, tliang@connect.ust.hk)


**Features**

1. supports placement with a large number of mixed-size macros with shape constraints in practical FPGA applications.
2. wirelength-driven, routability-aware, packing-aware, clock-aware, region-aware. (initially timing-driven with basic embedded static timing analysis engine)
3. a set of optional optimization techniques to improve mixed-size FPGA placement QoR
4. parallelizes the implementation of each stage of placement based on multi-threading
5. modularized function implementation and clear Doxygen documentation for easier further development
6. flexible and extensible JSON-based placement configuration
7. supports placement check-point importing/exporting
8. a set of pre-implementation benchmarks from latest practical FPGA applications
9. provides a set of Tcl scripts which extracts design netlist from Vivado and exports post-placement information to Vivado

**Implementation Overview**

<center>
<img src="overview.png" alt="Implementation Overview" title="Implementation Overview" width="800" /> 
</center>

**Acknowledgement**

We sincerely appreciate the kindly suggestions from reviewers, detailed explanations of UTPlaceF from [Dr. Wuxi Li](http://wuxili.net/#about), useful advice on Vivado metric usages from Dr. Stephen Yang, fruitful discussion on some previous works with [Ms. Yun Zhou](https://github.com/YunxZhou) and practical suggestions of the convenient usages of AMF-Placer from [Mr. Jing Mai](https://github.com/magic3007).


**Issue Report**

This project is under active development and far from perfect. We do want to make the placer useful for people in the community. Therefore,
* If you have any question/problem, please feel free to create an issue in the [GitHub Issue](https://github.com/zslwyuan/AMF-Placer/issues) or email us (Tingyuan LIANG, tliang@connect.ust.hk)
* We sincerely welcome code contribution to this project or suggestion in any approach!

(last updated Aug 17, 2021)
