/*****************************************************************************************************
*** Calcul de farm pour le jeu Raid Shadow Legend selon les rounds que vous jouez:
***      -12-3 Campagne
***      -Dragon 20
***      -Spider 20
***      -Spider H3
*** pour compiler:  
*** gcc -o Exe RaidFarm-FinaleVersion-1Fichier-GTK.c `pkg-config gtkmm-3.0 --cflags --libs` && ./Exe4 
*/
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#define ROWS 6
#define COLS 60

int SaisieEtoileChampion;
int SaisieLevelChampion;

int XPChampion;
int XPCumuleChampion;
int XPTotalChampion;
int XPMaxChampion;
int XPManquantChampion;

int i;

int Dragon20 = 5782 ;
int NRoundDragon20;

int AraigneeH3 =5999; 
int NRoundAraigneeH3;

int Araignee20 = 5800;
int NRoundAraignee20;

int CampagneBrutale12_6= 8800;
int NRoundCampagneBrutale12_6;

int NombreRound ;

long EnergieManquanteAraignee20;
long EnergieManquanteDragon20;
//long NRoundManquant12_3;
long EnergieManquanteCampagne12_6;
long EnergieManquanteAraigneeH3;
// Déclaration du tableau
int ChampionEtoilesXP[ROWS][COLS] = {
    {897, 1118, 1393, 1736, 2163, 2695, 3359, 4185, 5215},
    {1110, 1258, 1426, 1616, 1831, 2075, 2351, 2664, 3019, 3421, 3876, 4392, 4977, 5640, 6390, 7241, 8205, 9298, 10536},
    {1279, 1411, 1556, 1717, 1893, 2088, 2303, 2541, 2802, 3091, 3409, 3760, 4147, 4574, 5045, 5565, 6138, 6769, 7466, 8235, 9083, 10018, 11050, 12188, 13442, 14827, 16353, 18037, 19894},
    {1460, 1591, 1734, 1890, 2060, 2245, 2447, 2666, 2906, 3167, 3451, 3761, 4099, 4467, 4868, 5305, 5782, 6301, 6867, 7483, 8155, 8888, 9686, 10556, 11504, 12537, 13663, 14890, 16227, 17684, 19272, 21003, 22889, 24945, 27185, 29627, 32287, 35187, 38347},
    {1625, 1760, 1907, 2066, 2238, 2424, 2626, 2845, 3082, 3338, 3616, 3918, 4244, 4597, 4980, 5395, 5844, 6331, 6858, 7430, 8048, 8719, 9445, 10231, 11084, 12007, 13007, 14090, 15264, 16535, 17912, 19404, 21020, 22770, 24667, 26721, 28947, 31358, 33970, 36799, 39864, 43184, 46780, 50677, 54897, 59470, 64423, 69788, 75601},
    {1813, 1956, 2110, 2277, 2457, 2651, 2860, 3086, 3329, 3592, 3876, 4182, 4512, 4869, 5253, 5668, 6115, 6598, 7119, 7681, 8288, 8942, 9648, 10410, 11232, 12119, 13076, 14109, 15223, 16425, 17722, 19121, 20631, 22260, 24018, 25914, 27961, 30168, 32551, 35121, 37894, 40886, 44115, 47598, 51357, 55412, 59787, 64508, 69602, 75098, 81028, 87426, 94329, 101778, 109815, 118486, 127842, 137937, 148828}
};

/* *** Fonction question *** */
long Question()
{
//    printf("\n\t Entrez le nombre d'étoile du champion: ");
//    scanf ("%i",&SaisieEtoileChampion);
    // printf("\t Nombre d'étoile du champion: %i",SaisieEtoileChampion);

//    printf("\n\t Entrez le level du champion: ");
//    scanf ("%i",&SaisieLevelChampion);
    // printf("\t Level du champion: %i",SaisieLevelChampion);
//    SaisieEtoileChampion = row; 
    switch (SaisieEtoileChampion)
        {
        case 1 : XPMaxChampion = 22761; break;
        case 2 : XPMaxChampion = 81326; break;
        case 3 : XPMaxChampion = 200681; break;
        case 4 : XPMaxChampion = 449082; break;
        case 5 : XPMaxChampion = 963806; break;
        case 6 : XPMaxChampion = 2010869; break;     
        default : { printf("\n\n\t  ****** Erreur de saisie. *****"); return 0;} 
        }   
    XPChampion = ChampionEtoilesXP[(SaisieEtoileChampion -1)][(SaisieLevelChampion -1)];
    printf("\n\t XP du (%i étoiles) au (Level %i) : %i\n",SaisieEtoileChampion, SaisieLevelChampion,XPChampion);
        //printf ("\n\t*** Fin Question () **** *************************************************************\n");
return 0;
}

long CalculXPmanquant ()
{
for (i = 0; i < SaisieLevelChampion ; i++)
    {
        XPCumuleChampion = XPCumuleChampion + ChampionEtoilesXP[(SaisieEtoileChampion -1)][i];
        // printf("\n\t XPTotalChampion en cours: %i, level %i, ajout de %i XP.", XPTotalChampion, i ,(ChampionEtoilesXP[SaisieEtoileChampion][i]));
    }
//printf("\n\t **** XP cumulés du Champion: %i\n", XPCumuleChampion);
}

long Reponse()
{
    printf (" \n\t\t\t\t\t *** Récapitulatif ***.\n");
    
    XPChampion = ChampionEtoilesXP[(SaisieEtoileChampion -1)][(SaisieLevelChampion -1)];
    printf("\n\t %i XP du (%i étoiles) au (Level %i).\n",XPChampion,SaisieEtoileChampion, SaisieLevelChampion);

    XPManquantChampion =XPMaxChampion -XPCumuleChampion;

    NRoundAraignee20= XPManquantChampion / Araignee20;    //NombreRound = 
        EnergieManquanteAraignee20= NRoundAraignee20 * 16;
    
    NRoundDragon20= XPManquantChampion / Dragon20;
        EnergieManquanteDragon20= NRoundDragon20 * 16;

    NRoundCampagneBrutale12_6  = XPManquantChampion / CampagneBrutale12_6;
       EnergieManquanteCampagne12_6 = NRoundCampagneBrutale12_6 *8;
       
    NRoundAraigneeH3 = XPManquantChampion / AraigneeH3;
        EnergieManquanteAraigneeH3 = NRoundAraigneeH3 *20;
        
  //NRoundManquant12_3 = XPManquantChampion / 8;
    printf("\n\t*** %i *** XP cumulés du Champion.\n", XPCumuleChampion);
    //printf("\n\tXP du (%i étoiles) au (Level %i) : %i\n",SaisieEtoileChampion, SaisieLevelChampion,XPChampion);
    printf("\n\tXP Maximum du %i étoiles : %i\n",SaisieEtoileChampion,XPMaxChampion);
    printf("\n\tXP manquant du champion (%i étoiles) : %i\n",SaisieEtoileChampion,XPManquantChampion);    
    //printf (" \n\t\t\t\t\t **** Fin Reponse ***.\n\n");
    return 0;
}

long ResultatFarm ()
{
    printf (" \n\t\t\t\t\t **** Resultat Farm ***.\n");
    printf("\n\t Nécéssite %li Energies pour faire %i rounds Araignee-20 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n",EnergieManquanteAraignee20, NRoundAraignee20,Araignee20, XPManquantChampion, SaisieEtoileChampion);   
    printf("\n\t Nécéssite %li Energies pour faire %i rounds Dragon-20 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n",EnergieManquanteDragon20, NRoundDragon20,Dragon20, XPManquantChampion, SaisieEtoileChampion);   
    printf("\n\t Nécéssite %li Energies pour faire %i rounds Campagne 12-6 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n",EnergieManquanteCampagne12_6, NRoundCampagneBrutale12_6,CampagneBrutale12_6, XPManquantChampion, SaisieEtoileChampion);
    printf("\n\t Nécéssite %li Energies pour faire %i rounds Araignee-H3 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n",EnergieManquanteAraigneeH3, NRoundAraigneeH3,AraigneeH3, XPManquantChampion, SaisieEtoileChampion);
     
    return 0;
}










// Fonction pour remplir la combobox des colonnes en fonction de la ligne sélectionnée
void update_col_combo(GtkComboBoxText *col_combo, int row) {
    gtk_combo_box_text_remove_all(col_combo); // Supprime toutes les colonnes existantes

    for (int col = 0; col < COLS; col++) {
        if (ChampionEtoilesXP[row][col] != 0) { // Vérifie si la case contient une valeur
            gchar *label = g_strdup_printf("Level %d", col + 1);
            gtk_combo_box_text_append_text(col_combo, label);
            g_free(label);
        }
    }
}

// Fonction appelée lorsque le bouton "Calculer" est cliqué
void on_calculate_clicked(GtkWidget *widget, gpointer user_ChampionEtoilesXP) {
    GtkComboBoxText **combos = (GtkComboBoxText **)user_ChampionEtoilesXP;
    GtkComboBoxText *row_combo = combos[0];
    GtkComboBoxText *col_combo = combos[1];

    int row = gtk_combo_box_get_active(GTK_COMBO_BOX(row_combo));
    int col = gtk_combo_box_get_active(GTK_COMBO_BOX(col_combo));

    SaisieEtoileChampion = row;
    Question ();
    CalculXPmanquant ();
    Reponse();
    ResultatFarm ();


    if (row >= 0 && col >= 0) {
        int result = ChampionEtoilesXP[row][col];

        gchar *message = g_strdup_printf("\n\t Nécéssite %li Energies pour faire %i rounds Araignee-20 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n\n\t Nécéssite %li Energies pour faire %i rounds Dragon-20 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n\n\t Nécéssite %li Energies pour faire %i rounds Campagne 12-6 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n\n\t Nécéssite %li Energies pour faire %i rounds Araignee-H3 (%i XP) pour atteindre  %i XP, maximum d'un champion %i étoiles.\n",EnergieManquanteAraignee20, NRoundAraignee20,Araignee20, XPManquantChampion, SaisieEtoileChampion, EnergieManquanteDragon20, NRoundDragon20,Dragon20, XPManquantChampion, SaisieEtoileChampion,EnergieManquanteCampagne12_6, NRoundCampagneBrutale12_6,CampagneBrutale12_6, XPManquantChampion, SaisieEtoileChampion,EnergieManquanteAraigneeH3, NRoundAraigneeH3,AraigneeH3, XPManquantChampion, SaisieEtoileChampion);
        
        GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                   GTK_DIALOG_DESTROY_WITH_PARENT,
                                                   GTK_MESSAGE_INFO,
                                                   GTK_BUTTONS_OK,
                                                   "%s", message);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

        g_free(message);
    } else {
        GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                                   GTK_DIALOG_DESTROY_WITH_PARENT,
                                                   GTK_MESSAGE_WARNING,
                                                   GTK_BUTTONS_OK,
                                                   "Veuillez sélectionner une ligne et une colonne !");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

// Fonction appelée lorsque la ligne sélectionnée change
void on_row_changed(GtkComboBox *row_combo, gpointer user_ChampionEtoilesXP) {
    GtkComboBoxText *col_combo = GTK_COMBO_BOX_TEXT(user_ChampionEtoilesXP);
    int row = gtk_combo_box_get_active(row_combo);

    if (row >= 0) {
        update_col_combo(col_combo, row); // Met à jour les colonnes en fonction de la ligne sélectionnée
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculateur d'XP Farm RSL.");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Combobox pour les lignes
    GtkComboBoxText *row_combo = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    for (int i = 0; i < ROWS; i++) {
        gchar *label = g_strdup_printf("Etoiles %d", i + 1);
        gtk_combo_box_text_append_text(row_combo, label);
        g_free(label);
    }
    gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(row_combo), TRUE, TRUE, 0);

    // Combobox pour les colonnes
    GtkComboBoxText *col_combo = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(col_combo), TRUE, TRUE, 0);

    // Bouton pour calculer
    GtkWidget *calculate_button = gtk_button_new_with_label("Calculer");
    GtkComboBoxText *combos[2] = {row_combo, col_combo};
    g_signal_connect(calculate_button, "clicked", G_CALLBACK(on_calculate_clicked), combos);
    gtk_box_pack_start(GTK_BOX(vbox), calculate_button, TRUE, TRUE, 0);

    // Connecte le signal de changement de ligne
    g_signal_connect(row_combo, "changed", G_CALLBACK(on_row_changed), col_combo);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
