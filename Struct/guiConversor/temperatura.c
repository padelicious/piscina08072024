#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


// Funções de conversão (mesmas do seu código original)
void celsius(float temp);
void fahrenheit(float temp);
void kelvin(float temp);

// Função para lidar com o clique no botão "Converter"
void on_convert_clicked(GtkWidget *button, gpointer user_data) {
    // Obter a temperatura da caixa de entrada
    GtkWidget *entry = gtk_widget_get_toplevel(button);
    entry = gtk_bin_get_child(GTK_BIN(entry));
    const gchar *temp_str = gtk_entry_get_text(GTK_ENTRY(entry));
    float temp = atof(temp_str);

    // Obter a unidade selecionada da caixa de combinação
    GtkWidget *combo = gtk_widget_get_toplevel(button);
    combo = gtk_bin_get_child(GTK_BIN(combo));
    combo = gtk_bin_get_child(GTK_BIN(combo));
    int unit = gtk_combo_box_get_active(GTK_COMBO_BOX(combo));

    // Realizar a conversão com base na unidade selecionada
    if (unit == 0) {
        celsius(temp);
    } else if (unit == 1) {
        fahrenheit(temp);
    } else {
        kelvin(temp);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv); // Inicializar GTK

    // Criar a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Conversor de Temperatura");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);

    // Criar um contêiner de caixa vertical
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Criar um rótulo para a entrada de temperatura
    GtkWidget *label = gtk_label_new("Digite a temperatura:");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);

    // Criar uma caixa de entrada para a temperatura
    GtkWidget *entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    // Criar uma caixa de combinação para selecionar a unidade
    GtkWidget *combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Celsius");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Fahrenheit");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Kelvin");
    gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 0);

    // Criar um botão para converter a temperatura
    GtkWidget *button = gtk_button_new_with_label("Converter");
    g_signal_connect(button, "clicked", G_CALLBACK(on_convert_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

    // Mostrar todos os widgets
    gtk_widget_show_all(window);

    // Iniciar o loop principal do GTK
    gtk_main();

    return 0;
}

// Funções de conversão (mesmas do seu código original)
void celsius(float temp) {
    float kelvin, fahrenheit;
    fahrenheit = (temp * 9/5) + 32;
    kelvin = temp + 273.15;
    printf("%.2f° Celsius e %.2f° Fahrenheit e %.2f° Kelvin\n", temp, fahrenheit, kelvin);
}

void fahrenheit(float temp) {
    float kelvin, celsius;
    kelvin = (temp - 32) * 5/9 + 273.15;
    celsius = (temp - 32) * 5/9;
    printf("%.2f° Fahrenheit e %.2f° Celsius e %.2f° Kelvin\n", temp, celsius, kelvin);
}

void kelvin(float temp) {
    float celsius, fahrenheit;
    celsius = temp - 273.15;
    fahrenheit = (temp - 273.15) * 9/5 + 32;
    printf("%.2f° Kelvin e %.2f° Celsius e %.2f° Fahrenheit\n", temp, celsius, fahrenheit);
}
