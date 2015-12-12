# IntroClass ReadMe

This package contains the IntroClass benchmark set.

The full IntroClass set is hosted at http://repairbenchmarks.cs.umass.edu/IntroClass, and is a part of the Autorepair Benchmark Suite, a joint project between Carnegie-Mellon University and the University of Massachusetts. The homepage for the Autorepair Benchmark Suite is located at http://dijkstra.cs.virginia.edu/genprog/resources/autorepairbenchmarks .

# Directory Overview

```
introclass/
 |-Makefile
 |-bin/
 |-checksum/
 |--Makefile
 |--tests/
 |----blackbox/
 |--------1.in
 |--------1.out
 |----whitebox/
 |--f4a823174201234546789abcdeffff<repository ID hex string>.../
 |----Makefile
 |----001/
 |--------ae-001.log
 |--------blackbox\_test.sh
 |--------checksum.c
 |--------gp-001.log
 |--------Makefile
 |--------metadata.json
 |--------whitebox\_test.sh
 |----002/
 |--------<same as above>
 |--09F911029D74E35BD84156C5635688C0<next repository ID hex string>.../
 |-digits/
 |-...
```

Every directory's Makefile will compile the C programs in that directory or in all subdirectories.

The top-level directories represent assignment programs:

* checksum -- compute a simple checksum of a string
* digits -- compute the number of digits in an integer
* grade -- compute the letter grade corresponding to a percentage
* median -- give the median of three numbers
* smallest -- give the smallest of three numbers
* syllables -- give the number of English syllables in a string

Every subdirectory below each of these top-level directories represents a student's submitted attempts at solving the homework problems. These are numbered starting from the first revision that contained a solution to the benchmark program. Since each student could submit each assignment as many times as they wished, there are different numbers of subdirectories between students.

Since the students have sometimes submitted several times the same file, the benchmark contain duplicate files. The unique revisions are listed in */program-metadata.json.

| Project   | # Repo  | # defects (revisions) | # unique defects |
|-----------|---------|-----------------------|------------------|
| checksum  |      21 |                    69 |               47 |
| digits    |      55 |                   236 |              144 |
| grade     |      50 |                   268 |              136 |
| median    |      44 |                   232 |               98 |
| smallest  |      45 |                   177 |               84 |
| syllables |      44 |                   161 |               63 |
| Total     |     259 |                  1143 |              572 |
 
## Submissions

Each submission directory contains the C source code for the student submission named as `<benchmark>.c`. You can compile this to a binary with the Makefile in the directory.

To run the blackbox or whitebox test suites against a compiled submission, use the `blackbox_test.sh` and `whitebox_test.sh` scripts in a submission directory. This is described in detail in the Running section.

Finally, a submission directory also contains the Genprog and AE log files produced during our experiments in the paper *paper title*, and a file `medatada.json` that contains the program's output for each of the blackbox and whitebox tests, the tests the programs pass and fail, whether the program is nondeterministic (i.e., whether the test results sometimes differ), and the original Git revision of the submission.

# Building

The IntroClass benchmark set has no build dependencies outside the C standard library. Run `make` in any directory to build the programs in that directory and its subdirectories, if any.

# Running

To run the tests for a particular benchmark, invoke the script `whitebox_test.sh` or `blackbox_test.sh`. For convenience, every submission directory has a copy of these scripts, but they are identical and interchangeable. They take three arguments:

    genprog_tests.py [submission executable] [test index]

The submission executable is the student submission under test; the test index is a string pX or nX, representing the Xth (starting from the first) positive (passing) or negative (failing) test case.

The test scripts are structured so that they can be passed to Genprog or AE as a fitness evaluation script. 

The `genprog_tests.py` script is in the bin/ subdirectory of the benchmark package. It requires Python 3.3+, but nothing beyond that.


# Extending

To add new tests to the benchmark set, put the test input file in the appropriate tests directory (underneath its relevant benchmark program). Generate the output for the test using the reference implementation in bin/`<programname>`.

**The whitebox\_test.sh and blackbox\_test.sh scripts will not recognize custom tests.** These scripts are generated using the tests known to pass or fail each specific binary. They must be programmatically re-generated.

If you're planning on adding tests to the benchmark suite, it's therefore best not to rely on the test scripts. Have your infrastructure call genprog\_tests.py directly, or use the methods available when importing genprog\_tests.py as a Python module. genprog\_tests.py will use the pre-computed results for benchmark output if possible, but otherwise will run the reference binary given to tell if a test passes or fails. 