At QtCreator's "Welcome" screen,
press "Open Project" and navigate into this directory.

Open the "Wesnoth.config" file.

At the "Projects" screen, 
click on "Build Settings".

The "build directory" field is not used by scons.

Under "Build Steps", remove the "Make" item..

"Add Build Step"
"Custom process step"
"Command" enter "scons" or the full path if not in the search path.
"Commands arguments" : -j<number_of_your_cores_+1>

"Add Clean Steps"
same thing as for "Add Build Step"
"Commands arguments" : -c
