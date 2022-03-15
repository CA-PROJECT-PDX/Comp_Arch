# Comp_Arch

# There are three object files in tis directory
# 1) main_step  - STEP mode
# 2) main_v     - Verbose mode
# 3) main_s     - SIlent mode

##TO RUN WITH SHELL SCRIPT:
#sh MEMFILE_GENERATION/memfile_gen.sh MEMFILE_GENERATION/ASSEMBLY_FILES
#This memfile_gen.sh script takes all the assembly code from the path MEMFILE_GENERATION/ASSEMBLY_FILES/ and creates mem files in the path MEMFILE_GENERATION/MEMFILES/.

#sh Run.sh MEMFILE_GENERATION/MEMFILES main_s
#sh Run.sh MEMFILE_GENERATION/MEMFILES main_v
#sh Run.sh MEMFILE_GENERATION/MEMFILES main_step
#This takes all the input files in the path MEMFILE_GENERATION/MEMFILES/ and runs the test in main_v, main_step or main_s modes based on which of the above three commands are called.
#The output will be available in the path OUTPUT_FILES/ with specific object name and test name. For example "test1_main_v.out"



##TO RUN MANUALLY WITHOUT SCRIPT:
#To run a basic test, execute the example command - "./main_v"
#This automatically takes program.mem as input and takes default arguments for pc and sp.
#If the user wants to change the argument during run time, the below examples can be executed.
#"./main_v ip_file=MEMFILE_GENERATION/MEMFILES/test1.mem start_addr=8 stack_addr=65535"
#Default arguments are taken to main.c if no or fewer arguments are given



