namespace RCO2InstallerGui
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public const int WM_NCLBUTTONDOWN = 0xA1;
        public const int HT_CAPTION = 0x2;

        [System.Runtime.InteropServices.DllImport("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
        [System.Runtime.InteropServices.DllImport("user32.dll")]
        public static extern bool ReleaseCapture();

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                ReleaseCapture();
                SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
            }
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "Working...";
            string installPath = "C:\\RClientOptimizer2";
            if (!Directory.Exists(installPath))
            {
                Directory.CreateDirectory(installPath);
            }

            if (File.Exists(installPath + "\\RCO2.exe"))
            {
                File.Delete(installPath + "\\RCO2.exe");
            }

            var httpClient = new HttpClient();
            var httpResult = await httpClient.GetAsync("https://raw.githubusercontent.com/L8X/Roblox-Client-Optimizer/main/RCO2.exe");
            var resultStream = await httpResult.Content.ReadAsStreamAsync();
            var fileStream = File.Create(installPath + "\\RCO2.exe");
            resultStream.CopyTo(fileStream);
            fileStream.Close();

            httpResult = await httpClient.GetAsync("https://raw.githubusercontent.com/L8X/Roblox-Client-Optimizer/main/RCO2InstallerGui.exe");
            resultStream = await httpResult.Content.ReadAsStreamAsync();
            fileStream = File.Create(installPath + "\\RCO2InstallerGui.exe");
            resultStream.CopyTo(fileStream);
            fileStream.Close();

            httpResult = await httpClient.GetAsync("https://raw.githubusercontent.com/L8X/Roblox-Client-Optimizer/main/RCO2InstallerGui.dll");
            resultStream = await httpResult.Content.ReadAsStreamAsync();
            fileStream = File.Create(installPath + "\\RCO2InstallerGui.dll");
            resultStream.CopyTo(fileStream);
            fileStream.Close();

            httpResult = await httpClient.GetAsync("https://raw.githubusercontent.com/L8X/Roblox-Client-Optimizer/main/RCO2InstallerGui.runtimeconfig.json");
            resultStream = await httpResult.Content.ReadAsStreamAsync();
            fileStream = File.Create(installPath + "\\RCO2InstallerGui.runtimeconfig.json");
            resultStream.CopyTo(fileStream);
            fileStream.Close();

            Microsoft.Win32.RegistryKey key;
            key = Microsoft.Win32.Registry.CurrentUser.OpenSubKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run", true);
            if (key != null)
            {
                key.SetValue("RCO2", "C:\\RClientOptimizer\\RCO2.exe", Microsoft.Win32.RegistryValueKind.String);
                key.Close();
            }

            richTextBox1.Text = "Done installing the latest version of RCO2!\nFeel free to close this installer...";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "Working...";
            string installPath = "C:\\RClientOptimizer2";
            if (Directory.Exists(installPath))
            {
                Directory.Delete(installPath,true);
            }

            Microsoft.Win32.RegistryKey key;
            key = Microsoft.Win32.Registry.CurrentUser.OpenSubKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run", true);
            if (key != null)
            {
                if (key.GetValue("RCO2") != null)
                {
                    key.DeleteValue("RCO2");
                }
                key.Close();
            }

            richTextBox1.Text = "Sorry to see you go :(\nRCO2 has been uninstalled from your system...";
        }

        private void label2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
