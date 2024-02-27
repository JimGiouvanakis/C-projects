# C-projects


## PhoneBook
This is a project in c , that was created for the needs of my university.
It is practicly a phonebook with basic option.

You run it like this:
```
/program.exe -f
```
I have a help option if you want to see all the commands:
```
/program.exe -h
```

You can create the phonebook (txt file ) like this: 
```
/program.exe -f "filename" -new
```

You can create then the Record :
```
/program.exe -f "filename" -newentry "Name" "Phone"
```

You can change the Record:
```
/program.exe -f "filename" -changeentry "OldName" "NewPhone"
```

You can show the Record:
```
/program.exe -f "filename" -changeentry "OldName" "Phone"
```

You can  show all  Records:
```
/program.exe -f "filename" -changeentries
```

You can delete a Record:
```
/program.exe -f "filename" -deleteentry "Name"
```

You can delete all Records:
```
/program.exe -f "filename" -deleteentries
```

## Grading System

This program calculates the final grade of students based on their written exercises and exams.
The template is based in the template was asked by my University.

### How to Use

1. Compile the program.
2. Run the executable.
3. Follow the instructions to input data.
4. Input grades for the final exam and repeat examinations if needed.
5. The program will calculate the final grades and display them.

### Program Details

- **Input Data**: Reads student registration numbers and grades for written exercises.
- **Exams**: Determines if students have the right to participate in the final exam.
- **Input Grade**: Takes input for final exam grades and repeat examination grades.
- **Final Grade**: Calculates the final grades based on the written exercises and exam grades.
- **Print Data**: Displays the student data and final grades.
