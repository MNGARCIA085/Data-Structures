/*
Function consolidar(t1, t2, inf, sup)
    res = createTable()  // Initialize an empty table res
    // Iterate through the range [inf, sup]
    For i from inf to sup do
        // If i is defined in both t1 and t2
        If isDefinedInTable(t1, i) AND isDefinedInTable(t2, i) then
            value = getFromTable(t1, i) + getFromTable(t2, i)  // Sum the values from both tables
            insertIntoTable(res, i, value)  // Insert the sum into res at position i
        // If i is only defined in t1
        Else if isDefinedInTable(t1, i) then
            insertIntoTable(res, i, getFromTable(t1, i))  // Insert the value from t1 into res
        // If i is only defined in t2
        Else if isDefinedInTable(t2, i) then
            insertIntoTable(res, i, getFromTable(t2, i))  // Insert the value from t2 into res
        End If
    End For

    Return res  // Return the consolidated table res
End Function
*/



Tabla consolidar( Tabla t1 , Tabla t2 , unsigned int inf , unsigned int sup ){
    Tabla res= crearTabla();
    for (int i = inf; i <= sup; i++){
        if (estaDefinidoTabla(t1, i) && estaDefinidoTabla(t2, i)){
            insertarTabla(res, i ,  recuperarenTabla(t1,i) + recuperarenTabla(t2,i));
        }else if (estaDefinidoTabla(t1, i)){
            insertarTabla(res, i ,  recuperarenTabla(t1,i));
        }else if (estaDefinidoTabla(t2, i)){
            insertarTabla(res, i ,  recuperarenTabla(t2,i));
        }
    }
    return res;
}
