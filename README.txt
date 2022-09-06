##############################################################################
#
# Rilevazione dei parametri del forno di verniciatura
#
#
#
# Tutto serve per misurare la temperatura di 3 termo coppie sul disposte in
# vari punti del forno e la velocità lineare del forno misurando l'input di
# segnale (da 0 a 10 volt) dato allo stesso.
#
##############################################################################

Nella cartella sono presenti 3 file.

script_halt.py è un semplice script che permette di spegnere fisicamente 
raspberry pi se viene chiuso un contatto.

script.py deve essere lanciato sempre da raspberry pi e permette di creare un
file csv con i dati letti dalla USB collegata ad arduino. I file vengono 
nominati con la data del giorno della rilavazione.

sketch.ino è la configurazione di arduino che permette di impostare gli 
ingressi e i tempi di rilevazione.
