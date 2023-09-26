Program Lab2;

{$APPTYPE CONSOLE}
{$R *.res}

uses
  System.SysUtils;

Var
    Counter, Number, NFactFact, NMax: UInt64;
    IsCorrect: Boolean;

Const
    MIN = 1;
    MAX = 30;
    FIRSTNUMB = 1;
    NFACTFACTMIN = 1;

Begin

    Writeln('Данная программа принимает n, и считает 1*3*...*n для нечетного n и 2*4*...*n для четного n');
    Writeln('Введите n (n -- натуральное число, диапазон n: ', MIN , '...', MAX);

    NFactFact := NfACTfACTMIN;
    Counter := 1;

    Repeat
        IsCorrect := True;
        Try
            Readln(Number);
        Except
            Writeln('Проверьте корректность ввода данных!');
            Writeln('Диапазон значений n (n - натуральное число) : ', MIN,
              '...', MAX);
            IsCorrect := False;
        End;
        If IsCorrect And ((Number < MIN) Or (Number > MAX)) Then
        Begin
            Writeln('Повторите ввод! Диапазон значений n (n - натуральное число) : ', MIN,
              '...', MAX);
            IsCorrect := False;
        End;
    Until IsCorrect;

    NMax := Number + 1;

    If Number Mod 2 = 1 Then
    Begin
        For Counter := 1 To NMax Do
        Begin
            If Counter Mod 2 = 0 Then
                NFactFact := NFactFact * Counter
        End;
    End
    Else
    Begin
        For Counter := 2 To NMax Do
        Begin
            If Counter Mod 2 = 0 Then
                NFactFact := NFactFact * Counter;
        End;
    End;

    Writeln('n!! = ', NFactFact);
    Readln;

End.
