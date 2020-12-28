using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using System.Threading;
using System.Speech.Recognition;
using System.Speech.Synthesis;


namespace SerialPortTerminal
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.gbConfig = new System.Windows.Forms.GroupBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Restart = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.bCreateSP = new System.Windows.Forms.Button();
            this.cbRtsEnable = new System.Windows.Forms.ComboBox();
            this.cbDtrEnable = new System.Windows.Forms.ComboBox();
            this.cbStopbits = new System.Windows.Forms.ComboBox();
            this.cbHandshake = new System.Windows.Forms.ComboBox();
            this.cbParity = new System.Windows.Forms.ComboBox();
            this.cbDataBits = new System.Windows.Forms.ComboBox();
            this.cbBaudRate = new System.Windows.Forms.ComboBox();
            this.cbPort = new System.Windows.Forms.ComboBox();
            this.Recieved = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.bClearRecieved = new System.Windows.Forms.Button();
            this.btn_createGesture = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btn_setdefault = new System.Windows.Forms.Button();
            this.label26 = new System.Windows.Forms.Label();
            this.textBox19 = new System.Windows.Forms.TextBox();
            this.textBox21 = new System.Windows.Forms.TextBox();
            this.textBox18 = new System.Windows.Forms.TextBox();
            this.textBox20 = new System.Windows.Forms.TextBox();
            this.textBox16 = new System.Windows.Forms.TextBox();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox17 = new System.Windows.Forms.TextBox();
            this.label25 = new System.Windows.Forms.Label();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.label19 = new System.Windows.Forms.Label();
            this.label20 = new System.Windows.Forms.Label();
            this.label21 = new System.Windows.Forms.Label();
            this.label22 = new System.Windows.Forms.Label();
            this.textBox12 = new System.Windows.Forms.TextBox();
            this.textBox15 = new System.Windows.Forms.TextBox();
            this.textBox14 = new System.Windows.Forms.TextBox();
            this.label23 = new System.Windows.Forms.Label();
            this.label24 = new System.Windows.Forms.Label();
            this.vScrollBar27 = new System.Windows.Forms.VScrollBar();
            this.textBox11 = new System.Windows.Forms.TextBox();
            this.vScrollBar26 = new System.Windows.Forms.VScrollBar();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.vScrollBar25 = new System.Windows.Forms.VScrollBar();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.vScrollBar24 = new System.Windows.Forms.VScrollBar();
            this.textBox23 = new System.Windows.Forms.TextBox();
            this.textBox22 = new System.Windows.Forms.TextBox();
            this.vScrollBar23 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar22 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar21 = new System.Windows.Forms.VScrollBar();
            this.textBox26 = new System.Windows.Forms.TextBox();
            this.textBox24 = new System.Windows.Forms.TextBox();
            this.textBox25 = new System.Windows.Forms.TextBox();
            this.textBox27 = new System.Windows.Forms.TextBox();
            this.textBox28 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.vScrollBar20 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar19 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar18 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar17 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar16 = new System.Windows.Forms.VScrollBar();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.vScrollBar15 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar14 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar13 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar12 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar11 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar10 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar9 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar8 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar7 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar4 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar5 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar6 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar3 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar2 = new System.Windows.Forms.VScrollBar();
            this.vScrollBar1 = new System.Windows.Forms.VScrollBar();
            this.textBox13 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.gestures = new System.Windows.Forms.ComboBox();
            this.label27 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.Infinity = new System.Windows.Forms.Button();
            this.label32 = new System.Windows.Forms.Label();
            this.btn_stopGesture = new System.Windows.Forms.Button();
            this.btn_deleteGesture = new System.Windows.Forms.Button();
            this.btn_playGesture = new System.Windows.Forms.Button();
            this.btn_showGesture = new System.Windows.Forms.Button();
            this.btn_saveGesture = new System.Windows.Forms.Button();
            this.label31 = new System.Windows.Forms.Label();
            this.label30 = new System.Windows.Forms.Label();
            this.delay = new System.Windows.Forms.TextBox();
            this.steps = new System.Windows.Forms.ComboBox();
            this.label29 = new System.Windows.Forms.Label();
            this.label28 = new System.Windows.Forms.Label();
            this.gestureName = new System.Windows.Forms.TextBox();
            this.Recieved_Speech = new System.Windows.Forms.RichTextBox();
            this.btn_Speech = new System.Windows.Forms.Button();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.RgbS = new System.Windows.Forms.ComboBox();
            this.RgbMC = new System.Windows.Forms.ComboBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.RgbRep = new System.Windows.Forms.TextBox();
            this.RgbBr = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.gbConfig.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbConfig
            // 
            this.gbConfig.Controls.Add(this.label8);
            this.gbConfig.Controls.Add(this.label9);
            this.gbConfig.Controls.Add(this.label7);
            this.gbConfig.Controls.Add(this.label6);
            this.gbConfig.Controls.Add(this.label5);
            this.gbConfig.Controls.Add(this.label4);
            this.gbConfig.Controls.Add(this.Restart);
            this.gbConfig.Controls.Add(this.label3);
            this.gbConfig.Controls.Add(this.label2);
            this.gbConfig.Controls.Add(this.bCreateSP);
            this.gbConfig.Controls.Add(this.cbRtsEnable);
            this.gbConfig.Controls.Add(this.cbDtrEnable);
            this.gbConfig.Controls.Add(this.cbStopbits);
            this.gbConfig.Controls.Add(this.cbHandshake);
            this.gbConfig.Controls.Add(this.cbParity);
            this.gbConfig.Controls.Add(this.cbDataBits);
            this.gbConfig.Controls.Add(this.cbBaudRate);
            this.gbConfig.Controls.Add(this.cbPort);
            resources.ApplyResources(this.gbConfig, "gbConfig");
            this.gbConfig.Name = "gbConfig";
            this.gbConfig.TabStop = false;
            // 
            // label8
            // 
            resources.ApplyResources(this.label8, "label8");
            this.label8.Name = "label8";
            // 
            // label9
            // 
            resources.ApplyResources(this.label9, "label9");
            this.label9.Name = "label9";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.Name = "label7";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.Name = "label6";
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // Restart
            // 
            resources.ApplyResources(this.Restart, "Restart");
            this.Restart.Name = "Restart";
            this.Restart.Click += new System.EventHandler(this.Restart_Click_1);
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // bCreateSP
            // 
            resources.ApplyResources(this.bCreateSP, "bCreateSP");
            this.bCreateSP.Name = "bCreateSP";
            this.bCreateSP.UseVisualStyleBackColor = true;
            this.bCreateSP.Click += new System.EventHandler(this.bCreateSP_Click);
            // 
            // cbRtsEnable
            // 
            this.cbRtsEnable.FormattingEnabled = true;
            resources.ApplyResources(this.cbRtsEnable, "cbRtsEnable");
            this.cbRtsEnable.Name = "cbRtsEnable";
            // 
            // cbDtrEnable
            // 
            this.cbDtrEnable.FormattingEnabled = true;
            resources.ApplyResources(this.cbDtrEnable, "cbDtrEnable");
            this.cbDtrEnable.Name = "cbDtrEnable";
            // 
            // cbStopbits
            // 
            this.cbStopbits.FormattingEnabled = true;
            resources.ApplyResources(this.cbStopbits, "cbStopbits");
            this.cbStopbits.Name = "cbStopbits";
            // 
            // cbHandshake
            // 
            this.cbHandshake.FormattingEnabled = true;
            resources.ApplyResources(this.cbHandshake, "cbHandshake");
            this.cbHandshake.Name = "cbHandshake";
            // 
            // cbParity
            // 
            this.cbParity.FormattingEnabled = true;
            resources.ApplyResources(this.cbParity, "cbParity");
            this.cbParity.Name = "cbParity";
            // 
            // cbDataBits
            // 
            this.cbDataBits.FormattingEnabled = true;
            resources.ApplyResources(this.cbDataBits, "cbDataBits");
            this.cbDataBits.Name = "cbDataBits";
            // 
            // cbBaudRate
            // 
            this.cbBaudRate.FormattingEnabled = true;
            resources.ApplyResources(this.cbBaudRate, "cbBaudRate");
            this.cbBaudRate.Name = "cbBaudRate";
            // 
            // cbPort
            // 
            resources.ApplyResources(this.cbPort, "cbPort");
            this.cbPort.Name = "cbPort";
            // 
            // Recieved
            // 
            this.Recieved.FormattingEnabled = true;
            resources.ApplyResources(this.Recieved, "Recieved");
            this.Recieved.Name = "Recieved";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            // 
            // bClearRecieved
            // 
            resources.ApplyResources(this.bClearRecieved, "bClearRecieved");
            this.bClearRecieved.Name = "bClearRecieved";
            this.bClearRecieved.UseVisualStyleBackColor = true;
            this.bClearRecieved.Click += new System.EventHandler(this.bClearRecieved_Click);
            // 
            // btn_createGesture
            // 
            resources.ApplyResources(this.btn_createGesture, "btn_createGesture");
            this.btn_createGesture.Name = "btn_createGesture";
            this.btn_createGesture.UseVisualStyleBackColor = true;
            this.btn_createGesture.Click += new System.EventHandler(this.btn_createGesture_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.SystemColors.MenuHighlight;
            resources.ApplyResources(this.groupBox1, "groupBox1");
            this.groupBox1.Controls.Add(this.btn_setdefault);
            this.groupBox1.Controls.Add(this.label26);
            this.groupBox1.Controls.Add(this.textBox19);
            this.groupBox1.Controls.Add(this.textBox21);
            this.groupBox1.Controls.Add(this.textBox18);
            this.groupBox1.Controls.Add(this.textBox20);
            this.groupBox1.Controls.Add(this.textBox16);
            this.groupBox1.Controls.Add(this.textBox8);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.textBox17);
            this.groupBox1.Controls.Add(this.label25);
            this.groupBox1.Controls.Add(this.textBox7);
            this.groupBox1.Controls.Add(this.label19);
            this.groupBox1.Controls.Add(this.label20);
            this.groupBox1.Controls.Add(this.label21);
            this.groupBox1.Controls.Add(this.label22);
            this.groupBox1.Controls.Add(this.textBox12);
            this.groupBox1.Controls.Add(this.textBox15);
            this.groupBox1.Controls.Add(this.textBox14);
            this.groupBox1.Controls.Add(this.label23);
            this.groupBox1.Controls.Add(this.label24);
            this.groupBox1.Controls.Add(this.vScrollBar27);
            this.groupBox1.Controls.Add(this.textBox11);
            this.groupBox1.Controls.Add(this.vScrollBar26);
            this.groupBox1.Controls.Add(this.textBox6);
            this.groupBox1.Controls.Add(this.vScrollBar25);
            this.groupBox1.Controls.Add(this.textBox10);
            this.groupBox1.Controls.Add(this.textBox9);
            this.groupBox1.Controls.Add(this.vScrollBar24);
            this.groupBox1.Controls.Add(this.textBox23);
            this.groupBox1.Controls.Add(this.textBox22);
            this.groupBox1.Controls.Add(this.vScrollBar23);
            this.groupBox1.Controls.Add(this.vScrollBar22);
            this.groupBox1.Controls.Add(this.vScrollBar21);
            this.groupBox1.Controls.Add(this.textBox26);
            this.groupBox1.Controls.Add(this.textBox24);
            this.groupBox1.Controls.Add(this.textBox25);
            this.groupBox1.Controls.Add(this.textBox27);
            this.groupBox1.Controls.Add(this.textBox28);
            this.groupBox1.Controls.Add(this.textBox4);
            this.groupBox1.Controls.Add(this.vScrollBar20);
            this.groupBox1.Controls.Add(this.vScrollBar19);
            this.groupBox1.Controls.Add(this.vScrollBar18);
            this.groupBox1.Controls.Add(this.vScrollBar17);
            this.groupBox1.Controls.Add(this.vScrollBar16);
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.vScrollBar15);
            this.groupBox1.Controls.Add(this.vScrollBar14);
            this.groupBox1.Controls.Add(this.vScrollBar13);
            this.groupBox1.Controls.Add(this.vScrollBar12);
            this.groupBox1.Controls.Add(this.vScrollBar11);
            this.groupBox1.Controls.Add(this.vScrollBar10);
            this.groupBox1.Controls.Add(this.vScrollBar9);
            this.groupBox1.Controls.Add(this.vScrollBar8);
            this.groupBox1.Controls.Add(this.vScrollBar7);
            this.groupBox1.Controls.Add(this.vScrollBar4);
            this.groupBox1.Controls.Add(this.vScrollBar5);
            this.groupBox1.Controls.Add(this.vScrollBar6);
            this.groupBox1.Controls.Add(this.vScrollBar3);
            this.groupBox1.Controls.Add(this.vScrollBar2);
            this.groupBox1.Controls.Add(this.vScrollBar1);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.TabStop = false;
            // 
            // btn_setdefault
            // 
            resources.ApplyResources(this.btn_setdefault, "btn_setdefault");
            this.btn_setdefault.Name = "btn_setdefault";
            this.btn_setdefault.UseVisualStyleBackColor = true;
            this.btn_setdefault.Click += new System.EventHandler(this.btn_setdefault_Click);
            // 
            // label26
            // 
            resources.ApplyResources(this.label26, "label26");
            this.label26.Name = "label26";
            // 
            // textBox19
            // 
            resources.ApplyResources(this.textBox19, "textBox19");
            this.textBox19.Name = "textBox19";
            this.textBox19.TextChanged += new System.EventHandler(this.textBox19_TextChanged);
            // 
            // textBox21
            // 
            resources.ApplyResources(this.textBox21, "textBox21");
            this.textBox21.Name = "textBox21";
            this.textBox21.TextChanged += new System.EventHandler(this.textBox21_TextChanged);
            // 
            // textBox18
            // 
            resources.ApplyResources(this.textBox18, "textBox18");
            this.textBox18.Name = "textBox18";
            this.textBox18.TextChanged += new System.EventHandler(this.textBox18_TextChanged);
            // 
            // textBox20
            // 
            resources.ApplyResources(this.textBox20, "textBox20");
            this.textBox20.Name = "textBox20";
            this.textBox20.TextChanged += new System.EventHandler(this.textBox20_TextChanged);
            // 
            // textBox16
            // 
            resources.ApplyResources(this.textBox16, "textBox16");
            this.textBox16.Name = "textBox16";
            this.textBox16.TextChanged += new System.EventHandler(this.textBox16_TextChanged);
            // 
            // textBox8
            // 
            resources.ApplyResources(this.textBox8, "textBox8");
            this.textBox8.Name = "textBox8";
            this.textBox8.TextChanged += new System.EventHandler(this.textBox8_TextChanged);
            // 
            // textBox1
            // 
            resources.ApplyResources(this.textBox1, "textBox1");
            this.textBox1.Name = "textBox1";
            // 
            // textBox17
            // 
            resources.ApplyResources(this.textBox17, "textBox17");
            this.textBox17.Name = "textBox17";
            this.textBox17.TextChanged += new System.EventHandler(this.textBox17_TextChanged);
            // 
            // label25
            // 
            resources.ApplyResources(this.label25, "label25");
            this.label25.Name = "label25";
            // 
            // textBox7
            // 
            resources.ApplyResources(this.textBox7, "textBox7");
            this.textBox7.Name = "textBox7";
            this.textBox7.TextChanged += new System.EventHandler(this.textBox7_TextChanged);
            // 
            // label19
            // 
            resources.ApplyResources(this.label19, "label19");
            this.label19.Name = "label19";
            // 
            // label20
            // 
            resources.ApplyResources(this.label20, "label20");
            this.label20.Name = "label20";
            // 
            // label21
            // 
            resources.ApplyResources(this.label21, "label21");
            this.label21.Name = "label21";
            // 
            // label22
            // 
            resources.ApplyResources(this.label22, "label22");
            this.label22.Name = "label22";
            // 
            // textBox12
            // 
            resources.ApplyResources(this.textBox12, "textBox12");
            this.textBox12.Name = "textBox12";
            this.textBox12.TextChanged += new System.EventHandler(this.textBox12_TextChanged);
            // 
            // textBox15
            // 
            resources.ApplyResources(this.textBox15, "textBox15");
            this.textBox15.Name = "textBox15";
            this.textBox15.TextChanged += new System.EventHandler(this.textBox15_TextChanged);
            // 
            // textBox14
            // 
            resources.ApplyResources(this.textBox14, "textBox14");
            this.textBox14.Name = "textBox14";
            this.textBox14.TextChanged += new System.EventHandler(this.textBox14_TextChanged);
            // 
            // label23
            // 
            resources.ApplyResources(this.label23, "label23");
            this.label23.Name = "label23";
            this.label23.Click += new System.EventHandler(this.label23_Click);
            // 
            // label24
            // 
            resources.ApplyResources(this.label24, "label24");
            this.label24.Name = "label24";
            // 
            // vScrollBar27
            // 
            resources.ApplyResources(this.vScrollBar27, "vScrollBar27");
            this.vScrollBar27.Maximum = 180;
            this.vScrollBar27.Name = "vScrollBar27";
            this.vScrollBar27.Value = 90;
            this.vScrollBar27.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar27_Scroll);
            // 
            // textBox11
            // 
            resources.ApplyResources(this.textBox11, "textBox11");
            this.textBox11.Name = "textBox11";
            this.textBox11.TextChanged += new System.EventHandler(this.textBox11_TextChanged);
            // 
            // vScrollBar26
            // 
            resources.ApplyResources(this.vScrollBar26, "vScrollBar26");
            this.vScrollBar26.Maximum = 180;
            this.vScrollBar26.Name = "vScrollBar26";
            this.vScrollBar26.Value = 90;
            this.vScrollBar26.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar26_Scroll);
            // 
            // textBox6
            // 
            resources.ApplyResources(this.textBox6, "textBox6");
            this.textBox6.Name = "textBox6";
            this.textBox6.TextChanged += new System.EventHandler(this.textBox6_TextChanged);
            // 
            // vScrollBar25
            // 
            resources.ApplyResources(this.vScrollBar25, "vScrollBar25");
            this.vScrollBar25.Maximum = 180;
            this.vScrollBar25.Name = "vScrollBar25";
            this.vScrollBar25.Value = 90;
            this.vScrollBar25.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar25_Scroll);
            // 
            // textBox10
            // 
            resources.ApplyResources(this.textBox10, "textBox10");
            this.textBox10.Name = "textBox10";
            this.textBox10.TextChanged += new System.EventHandler(this.textBox10_TextChanged);
            // 
            // textBox9
            // 
            resources.ApplyResources(this.textBox9, "textBox9");
            this.textBox9.Name = "textBox9";
            this.textBox9.TextChanged += new System.EventHandler(this.textBox9_TextChanged);
            // 
            // vScrollBar24
            // 
            resources.ApplyResources(this.vScrollBar24, "vScrollBar24");
            this.vScrollBar24.Maximum = 180;
            this.vScrollBar24.Name = "vScrollBar24";
            this.vScrollBar24.Value = 90;
            this.vScrollBar24.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar24_Scroll);
            // 
            // textBox23
            // 
            resources.ApplyResources(this.textBox23, "textBox23");
            this.textBox23.Name = "textBox23";
            this.textBox23.TextChanged += new System.EventHandler(this.textBox23_TextChanged);
            // 
            // textBox22
            // 
            resources.ApplyResources(this.textBox22, "textBox22");
            this.textBox22.Name = "textBox22";
            this.textBox22.TextChanged += new System.EventHandler(this.textBox22_TextChanged);
            // 
            // vScrollBar23
            // 
            resources.ApplyResources(this.vScrollBar23, "vScrollBar23");
            this.vScrollBar23.Maximum = 180;
            this.vScrollBar23.Name = "vScrollBar23";
            this.vScrollBar23.Value = 90;
            this.vScrollBar23.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar23_Scroll);
            // 
            // vScrollBar22
            // 
            resources.ApplyResources(this.vScrollBar22, "vScrollBar22");
            this.vScrollBar22.Maximum = 180;
            this.vScrollBar22.Name = "vScrollBar22";
            this.vScrollBar22.Value = 90;
            this.vScrollBar22.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar22_Scroll);
            // 
            // vScrollBar21
            // 
            resources.ApplyResources(this.vScrollBar21, "vScrollBar21");
            this.vScrollBar21.Maximum = 180;
            this.vScrollBar21.Name = "vScrollBar21";
            this.vScrollBar21.Value = 90;
            this.vScrollBar21.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar21_Scroll);
            // 
            // textBox26
            // 
            resources.ApplyResources(this.textBox26, "textBox26");
            this.textBox26.Name = "textBox26";
            this.textBox26.TextChanged += new System.EventHandler(this.textBox26_TextChanged);
            // 
            // textBox24
            // 
            resources.ApplyResources(this.textBox24, "textBox24");
            this.textBox24.Name = "textBox24";
            this.textBox24.TextChanged += new System.EventHandler(this.textBox24_TextChanged);
            // 
            // textBox25
            // 
            resources.ApplyResources(this.textBox25, "textBox25");
            this.textBox25.Name = "textBox25";
            this.textBox25.TextChanged += new System.EventHandler(this.textBox25_TextChanged);
            // 
            // textBox27
            // 
            resources.ApplyResources(this.textBox27, "textBox27");
            this.textBox27.Name = "textBox27";
            this.textBox27.TextChanged += new System.EventHandler(this.textBox27_TextChanged);
            // 
            // textBox28
            // 
            resources.ApplyResources(this.textBox28, "textBox28");
            this.textBox28.Name = "textBox28";
            this.textBox28.TextChanged += new System.EventHandler(this.textBox28_TextChanged);
            // 
            // textBox4
            // 
            resources.ApplyResources(this.textBox4, "textBox4");
            this.textBox4.Name = "textBox4";
            this.textBox4.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // vScrollBar20
            // 
            resources.ApplyResources(this.vScrollBar20, "vScrollBar20");
            this.vScrollBar20.Maximum = 180;
            this.vScrollBar20.Name = "vScrollBar20";
            this.vScrollBar20.Value = 90;
            this.vScrollBar20.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar20_Scroll);
            // 
            // vScrollBar19
            // 
            resources.ApplyResources(this.vScrollBar19, "vScrollBar19");
            this.vScrollBar19.Maximum = 180;
            this.vScrollBar19.Name = "vScrollBar19";
            this.vScrollBar19.Value = 90;
            this.vScrollBar19.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar19_Scroll);
            // 
            // vScrollBar18
            // 
            resources.ApplyResources(this.vScrollBar18, "vScrollBar18");
            this.vScrollBar18.Maximum = 180;
            this.vScrollBar18.Name = "vScrollBar18";
            this.vScrollBar18.Value = 90;
            this.vScrollBar18.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar18_Scroll);
            // 
            // vScrollBar17
            // 
            resources.ApplyResources(this.vScrollBar17, "vScrollBar17");
            this.vScrollBar17.Maximum = 180;
            this.vScrollBar17.Name = "vScrollBar17";
            this.vScrollBar17.Value = 90;
            this.vScrollBar17.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar17_Scroll);
            // 
            // vScrollBar16
            // 
            resources.ApplyResources(this.vScrollBar16, "vScrollBar16");
            this.vScrollBar16.Maximum = 180;
            this.vScrollBar16.Name = "vScrollBar16";
            this.vScrollBar16.Value = 90;
            this.vScrollBar16.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar16_Scroll);
            // 
            // textBox2
            // 
            resources.ApplyResources(this.textBox2, "textBox2");
            this.textBox2.Name = "textBox2";
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // vScrollBar15
            // 
            resources.ApplyResources(this.vScrollBar15, "vScrollBar15");
            this.vScrollBar15.Maximum = 180;
            this.vScrollBar15.Name = "vScrollBar15";
            this.vScrollBar15.Value = 90;
            this.vScrollBar15.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar15_Scroll);
            // 
            // vScrollBar14
            // 
            resources.ApplyResources(this.vScrollBar14, "vScrollBar14");
            this.vScrollBar14.Maximum = 180;
            this.vScrollBar14.Name = "vScrollBar14";
            this.vScrollBar14.Value = 90;
            this.vScrollBar14.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar14_Scroll);
            // 
            // vScrollBar13
            // 
            resources.ApplyResources(this.vScrollBar13, "vScrollBar13");
            this.vScrollBar13.Maximum = 180;
            this.vScrollBar13.Name = "vScrollBar13";
            this.vScrollBar13.Value = 90;
            this.vScrollBar13.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar13_Scroll);
            // 
            // vScrollBar12
            // 
            resources.ApplyResources(this.vScrollBar12, "vScrollBar12");
            this.vScrollBar12.Maximum = 180;
            this.vScrollBar12.Name = "vScrollBar12";
            this.vScrollBar12.Value = 90;
            this.vScrollBar12.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar12_Scroll);
            // 
            // vScrollBar11
            // 
            resources.ApplyResources(this.vScrollBar11, "vScrollBar11");
            this.vScrollBar11.Maximum = 180;
            this.vScrollBar11.Name = "vScrollBar11";
            this.vScrollBar11.Value = 90;
            this.vScrollBar11.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar11_Scroll);
            // 
            // vScrollBar10
            // 
            resources.ApplyResources(this.vScrollBar10, "vScrollBar10");
            this.vScrollBar10.Maximum = 180;
            this.vScrollBar10.Name = "vScrollBar10";
            this.vScrollBar10.Value = 90;
            this.vScrollBar10.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar10_Scroll);
            // 
            // vScrollBar9
            // 
            resources.ApplyResources(this.vScrollBar9, "vScrollBar9");
            this.vScrollBar9.Maximum = 180;
            this.vScrollBar9.Name = "vScrollBar9";
            this.vScrollBar9.Value = 90;
            this.vScrollBar9.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar9_Scroll);
            // 
            // vScrollBar8
            // 
            resources.ApplyResources(this.vScrollBar8, "vScrollBar8");
            this.vScrollBar8.Maximum = 180;
            this.vScrollBar8.Name = "vScrollBar8";
            this.vScrollBar8.Value = 90;
            this.vScrollBar8.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar8_Scroll);
            // 
            // vScrollBar7
            // 
            resources.ApplyResources(this.vScrollBar7, "vScrollBar7");
            this.vScrollBar7.Maximum = 180;
            this.vScrollBar7.Name = "vScrollBar7";
            this.vScrollBar7.Value = 90;
            this.vScrollBar7.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar7_Scroll);
            // 
            // vScrollBar4
            // 
            resources.ApplyResources(this.vScrollBar4, "vScrollBar4");
            this.vScrollBar4.Maximum = 180;
            this.vScrollBar4.Name = "vScrollBar4";
            this.vScrollBar4.Value = 90;
            this.vScrollBar4.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar4_Scroll);
            // 
            // vScrollBar5
            // 
            resources.ApplyResources(this.vScrollBar5, "vScrollBar5");
            this.vScrollBar5.Maximum = 180;
            this.vScrollBar5.Name = "vScrollBar5";
            this.vScrollBar5.Value = 90;
            this.vScrollBar5.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar5_Scroll);
            // 
            // vScrollBar6
            // 
            resources.ApplyResources(this.vScrollBar6, "vScrollBar6");
            this.vScrollBar6.Maximum = 180;
            this.vScrollBar6.Name = "vScrollBar6";
            this.vScrollBar6.Value = 90;
            this.vScrollBar6.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar6_Scroll);
            // 
            // vScrollBar3
            // 
            resources.ApplyResources(this.vScrollBar3, "vScrollBar3");
            this.vScrollBar3.Maximum = 180;
            this.vScrollBar3.Name = "vScrollBar3";
            this.vScrollBar3.Value = 90;
            this.vScrollBar3.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar3_Scroll);
            // 
            // vScrollBar2
            // 
            resources.ApplyResources(this.vScrollBar2, "vScrollBar2");
            this.vScrollBar2.Maximum = 180;
            this.vScrollBar2.Name = "vScrollBar2";
            this.vScrollBar2.Value = 90;
            this.vScrollBar2.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar2_Scroll);
            // 
            // vScrollBar1
            // 
            resources.ApplyResources(this.vScrollBar1, "vScrollBar1");
            this.vScrollBar1.Maximum = 180;
            this.vScrollBar1.Name = "vScrollBar1";
            this.vScrollBar1.Value = 90;
            // 
            // textBox13
            // 
            resources.ApplyResources(this.textBox13, "textBox13");
            this.textBox13.Name = "textBox13";
            this.textBox13.TextChanged += new System.EventHandler(this.textBox13_TextChanged);
            // 
            // textBox3
            // 
            resources.ApplyResources(this.textBox3, "textBox3");
            this.textBox3.Name = "textBox3";
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // gestures
            // 
            this.gestures.FormattingEnabled = true;
            resources.ApplyResources(this.gestures, "gestures");
            this.gestures.Name = "gestures";
            // 
            // label27
            // 
            resources.ApplyResources(this.label27, "label27");
            this.label27.Name = "label27";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.Infinity);
            this.groupBox2.Controls.Add(this.label32);
            this.groupBox2.Controls.Add(this.btn_stopGesture);
            this.groupBox2.Controls.Add(this.btn_deleteGesture);
            this.groupBox2.Controls.Add(this.btn_playGesture);
            this.groupBox2.Controls.Add(this.btn_showGesture);
            this.groupBox2.Controls.Add(this.btn_saveGesture);
            this.groupBox2.Controls.Add(this.label31);
            this.groupBox2.Controls.Add(this.label30);
            this.groupBox2.Controls.Add(this.delay);
            this.groupBox2.Controls.Add(this.steps);
            this.groupBox2.Controls.Add(this.label29);
            this.groupBox2.Controls.Add(this.label28);
            this.groupBox2.Controls.Add(this.gestureName);
            this.groupBox2.Controls.Add(this.label27);
            this.groupBox2.Controls.Add(this.gestures);
            this.groupBox2.Controls.Add(this.btn_createGesture);
            resources.ApplyResources(this.groupBox2, "groupBox2");
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.TabStop = false;
            // 
            // Infinity
            // 
            resources.ApplyResources(this.Infinity, "Infinity");
            this.Infinity.Name = "Infinity";
            this.Infinity.UseVisualStyleBackColor = true;
            this.Infinity.Click += new System.EventHandler(this.Infinity_Click);
            // 
            // label32
            // 
            resources.ApplyResources(this.label32, "label32");
            this.label32.Name = "label32";
            // 
            // btn_stopGesture
            // 
            resources.ApplyResources(this.btn_stopGesture, "btn_stopGesture");
            this.btn_stopGesture.Name = "btn_stopGesture";
            this.btn_stopGesture.UseVisualStyleBackColor = true;
            this.btn_stopGesture.Click += new System.EventHandler(this.btn_stopGesture_Click);
            // 
            // btn_deleteGesture
            // 
            resources.ApplyResources(this.btn_deleteGesture, "btn_deleteGesture");
            this.btn_deleteGesture.Name = "btn_deleteGesture";
            this.btn_deleteGesture.UseVisualStyleBackColor = true;
            this.btn_deleteGesture.Click += new System.EventHandler(this.btn_deleteGesture_Click);
            // 
            // btn_playGesture
            // 
            resources.ApplyResources(this.btn_playGesture, "btn_playGesture");
            this.btn_playGesture.Name = "btn_playGesture";
            this.btn_playGesture.UseVisualStyleBackColor = true;
            this.btn_playGesture.Click += new System.EventHandler(this.btn_playGesture_Click);
            // 
            // btn_showGesture
            // 
            resources.ApplyResources(this.btn_showGesture, "btn_showGesture");
            this.btn_showGesture.Name = "btn_showGesture";
            this.btn_showGesture.UseVisualStyleBackColor = true;
            this.btn_showGesture.Click += new System.EventHandler(this.btn_showGesture_Click);
            // 
            // btn_saveGesture
            // 
            resources.ApplyResources(this.btn_saveGesture, "btn_saveGesture");
            this.btn_saveGesture.Name = "btn_saveGesture";
            this.btn_saveGesture.UseVisualStyleBackColor = true;
            this.btn_saveGesture.Click += new System.EventHandler(this.btn_saveGesture_Click);
            // 
            // label31
            // 
            resources.ApplyResources(this.label31, "label31");
            this.label31.Name = "label31";
            // 
            // label30
            // 
            resources.ApplyResources(this.label30, "label30");
            this.label30.Name = "label30";
            // 
            // delay
            // 
            resources.ApplyResources(this.delay, "delay");
            this.delay.Name = "delay";
            // 
            // steps
            // 
            this.steps.FormattingEnabled = true;
            resources.ApplyResources(this.steps, "steps");
            this.steps.Name = "steps";
            // 
            // label29
            // 
            resources.ApplyResources(this.label29, "label29");
            this.label29.Name = "label29";
            // 
            // label28
            // 
            resources.ApplyResources(this.label28, "label28");
            this.label28.Name = "label28";
            // 
            // gestureName
            // 
            resources.ApplyResources(this.gestureName, "gestureName");
            this.gestureName.Name = "gestureName";
            // 
            // Recieved_Speech
            // 
            resources.ApplyResources(this.Recieved_Speech, "Recieved_Speech");
            this.Recieved_Speech.Name = "Recieved_Speech";
            // 
            // btn_Speech
            // 
            resources.ApplyResources(this.btn_Speech, "btn_Speech");
            this.btn_Speech.Name = "btn_Speech";
            this.btn_Speech.UseVisualStyleBackColor = true;
            this.btn_Speech.Click += new System.EventHandler(this.btn_Speech_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            resources.ApplyResources(this.contextMenuStrip1, "contextMenuStrip1");
            // 
            // RgbS
            // 
            this.RgbS.FormattingEnabled = true;
            resources.ApplyResources(this.RgbS, "RgbS");
            this.RgbS.Name = "RgbS";
            // 
            // RgbMC
            // 
            resources.ApplyResources(this.RgbMC, "RgbMC");
            this.RgbMC.Name = "RgbMC";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.button1);
            this.groupBox3.Controls.Add(this.label13);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Controls.Add(this.RgbRep);
            this.groupBox3.Controls.Add(this.RgbBr);
            this.groupBox3.Controls.Add(this.RgbS);
            this.groupBox3.Controls.Add(this.RgbMC);
            resources.ApplyResources(this.groupBox3, "groupBox3");
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.TabStop = false;
            // 
            // label13
            // 
            resources.ApplyResources(this.label13, "label13");
            this.label13.Name = "label13";
            // 
            // label12
            // 
            resources.ApplyResources(this.label12, "label12");
            this.label12.Name = "label12";
            // 
            // label11
            // 
            resources.ApplyResources(this.label11, "label11");
            this.label11.Name = "label11";
            // 
            // label10
            // 
            resources.ApplyResources(this.label10, "label10");
            this.label10.Name = "label10";
            // 
            // RgbRep
            // 
            resources.ApplyResources(this.RgbRep, "RgbRep");
            this.RgbRep.Name = "RgbRep";
            // 
            // RgbBr
            // 
            resources.ApplyResources(this.RgbBr, "RgbBr");
            this.RgbBr.Name = "RgbBr";
            this.RgbBr.TextChanged += new System.EventHandler(this.RgbBr_TextChanged);
            // 
            // button1
            // 
            resources.ApplyResources(this.button1, "button1");
            this.button1.Name = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox13);
            this.Controls.Add(this.btn_Speech);
            this.Controls.Add(this.Recieved_Speech);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.gbConfig);
            this.Controls.Add(this.Recieved);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.bClearRecieved);
            this.ForeColor = System.Drawing.SystemColors.Desktop;
            this.Name = "Form1";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gbConfig.ResumeLayout(false);
            this.gbConfig.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox gbConfig;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button bCreateSP;
        private System.Windows.Forms.ComboBox cbDataBits;
        private System.Windows.Forms.ComboBox cbBaudRate;
        private System.Windows.Forms.ComboBox cbPort;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox cbRtsEnable;
        private System.Windows.Forms.ComboBox cbDtrEnable;
        private System.Windows.Forms.ComboBox cbStopbits;
        private System.Windows.Forms.ComboBox cbHandshake;
        private System.Windows.Forms.ComboBox cbParity;
        private System.Windows.Forms.ListBox Recieved;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button bClearRecieved;
        private System.Windows.Forms.Button Restart;
        private System.Windows.Forms.Button btn_createGesture;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.VScrollBar vScrollBar27;
        private System.Windows.Forms.VScrollBar vScrollBar26;
        private System.Windows.Forms.VScrollBar vScrollBar25;
        private System.Windows.Forms.VScrollBar vScrollBar24;
        private System.Windows.Forms.VScrollBar vScrollBar23;
        private System.Windows.Forms.VScrollBar vScrollBar22;
        private System.Windows.Forms.VScrollBar vScrollBar21;
        private System.Windows.Forms.VScrollBar vScrollBar20;
        private System.Windows.Forms.VScrollBar vScrollBar19;
        private System.Windows.Forms.VScrollBar vScrollBar18;
        private System.Windows.Forms.VScrollBar vScrollBar17;
        private System.Windows.Forms.VScrollBar vScrollBar16;
        private System.Windows.Forms.VScrollBar vScrollBar15;
        private System.Windows.Forms.VScrollBar vScrollBar14;
        private System.Windows.Forms.VScrollBar vScrollBar13;
        private System.Windows.Forms.VScrollBar vScrollBar12;
        private System.Windows.Forms.VScrollBar vScrollBar11;
        private System.Windows.Forms.VScrollBar vScrollBar10;
        private System.Windows.Forms.VScrollBar vScrollBar9;
        private System.Windows.Forms.VScrollBar vScrollBar8;
        private System.Windows.Forms.VScrollBar vScrollBar7;
        private System.Windows.Forms.VScrollBar vScrollBar4;
        private System.Windows.Forms.VScrollBar vScrollBar5;
        private System.Windows.Forms.VScrollBar vScrollBar6;
        private System.Windows.Forms.VScrollBar vScrollBar3;
        private System.Windows.Forms.VScrollBar vScrollBar2;
        private System.Windows.Forms.VScrollBar vScrollBar1;
        private System.Windows.Forms.Label label26;
        private System.Windows.Forms.Label label25;
        private System.Windows.Forms.ComboBox gestures;
        private System.Windows.Forms.Label label27;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label28;
        private System.Windows.Forms.TextBox gestureName;
        private System.Windows.Forms.Button Infinity;
        private System.Windows.Forms.Label label32;
        private System.Windows.Forms.Button btn_stopGesture;
        private System.Windows.Forms.Button btn_deleteGesture;
        private System.Windows.Forms.Button btn_playGesture;
        private System.Windows.Forms.Button btn_showGesture;
        private System.Windows.Forms.Button btn_saveGesture;
        private System.Windows.Forms.Label label31;
        private System.Windows.Forms.Label label30;
        private System.Windows.Forms.TextBox delay;
        private System.Windows.Forms.ComboBox steps;
        private System.Windows.Forms.Label label29;
        private System.Windows.Forms.Button btn_setdefault;
        private System.Windows.Forms.RichTextBox Recieved_Speech;
        private System.Windows.Forms.Button btn_Speech;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox28;
        private System.Windows.Forms.TextBox textBox27;
        private System.Windows.Forms.TextBox textBox26;
        private System.Windows.Forms.TextBox textBox25;
        private System.Windows.Forms.TextBox textBox24;
        private System.Windows.Forms.TextBox textBox23;
        private System.Windows.Forms.TextBox textBox22;
        private System.Windows.Forms.TextBox textBox21;
        private System.Windows.Forms.TextBox textBox20;
        private System.Windows.Forms.TextBox textBox19;
        private System.Windows.Forms.TextBox textBox18;
        private System.Windows.Forms.TextBox textBox17;
        private System.Windows.Forms.TextBox textBox16;
        private System.Windows.Forms.TextBox textBox15;
        private System.Windows.Forms.TextBox textBox14;
        private System.Windows.Forms.TextBox textBox13;
        private System.Windows.Forms.TextBox textBox12;
        private System.Windows.Forms.TextBox textBox11;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.ComboBox RgbMC;
        private System.Windows.Forms.ComboBox RgbS;
        private GroupBox groupBox3;
        private Label label10;
        private TextBox RgbRep;
        private TextBox RgbBr;
        private Label label13;
        private Label label12;
        private Label label11;
        private Button button1;
    }
}

