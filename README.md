# simulink-argos

### Getting Started with Simulink ###
Run the following script to open an example model.

```>> startupEnvironment```

To generate code, use the MATLAB script below.

```>> exportGeneratedCode```

### Compiling Examples ###

To compile the examples, open up a shell, 
go to the root directory of this repository, and enter:

```$ cd examples```
```$ mkdir build```
```$ cd build```

To produce debuggable code (slow), type:

$ cmake -DCMAKE_BUILD_TYPE=Debug ..

To produce fast but not debuggable code, type:

$ cmake -DCMAKE_BUILD_TYPE=Release ..

Finally, launch the compilation with the command:

$ make

If you find no error, you're ready to go to the next phase.

### Running Examples ###

To run the examples, go to the ```examples``` folder.

```$ argos3 -c experiments/matlab_gen_test.argos``` 
```$ argos3 -c experiments/matlab_gen_test_multiple.argos```