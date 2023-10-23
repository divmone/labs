Program lab2_2;

Const
    ONE = 1;
    TWO = 2;
    ZERO = 0;
    NINE = 9;
    TEN = 10;
    ArraySi = 50;

Procedure PrintNumber(NumberArray: Array Of Integer; Length: Integer);
Var
    Index, LastIndex: Integer;
Begin
    LastIndex := Length - TWO;
    Write(#13#10'Ваше число ---->  ');
    For Index := LastIndex Downto ZERO Do
        Write(NumberArray[Index]);
End;

Procedure FindMinNumber;
Var
    Index, CurrentNumber, CarryOver: Integer;
    IsFound: Boolean;
    NumberArray: Array [1 .. ArraySi] Of Integer;

Begin
    Index := ONE;
    CurrentNumber := TWO;
    CarryOver := ZERO;
    IsFound := False;

    While (Index < ArraySi) And (Not IsFound) Do
    Begin
        CurrentNumber := CurrentNumber * TWO + CarryOver;
        If CurrentNumber > NINE Then
        Begin
            CarryOver := ONE;
            CurrentNumber := CurrentNumber - TEN;
        End
        Else
            CarryOver := ZERO;
        NumberArray[Index] := CurrentNumber;
        IsFound := (CurrentNumber = TWO) And (CarryOver = ZERO);
        Inc(Index);
    End;
    PrintNumber(NumberArray, Index);
End;

Procedure PrintProblemStatement();
Begin
    Writeln('Данная программа находит самое маленькое натуральное число, для которого верно следующее условие: ',
      #10, 'Eсли последнюю цифру этого числа перенести и поставить перед первой цифрой, то получится число, в два раза больше исходного числа.');
End;

Procedure Main();
Begin
    PrintProblemStatement();
    FindMinNumber();
End;

Begin
    Main;
    Readln;

End.
