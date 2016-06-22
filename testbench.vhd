library ieee;
use ieee.std_logic_1164.all;

entity test_bench is
end test_bench;

architecture behavior of test_bench is
    component isa_lpt port(
        clock        : in  std_logic;
        isa_reset    : in  std_logic;
        isa_address  : in  std_logic_vector(9 downto 0);
        isa_aen      : in  std_logic;
        isa_ior      : in  std_logic;
        isa_iow      : in  std_logic;
        isa_data_in  : in  std_logic_vector(7 downto 0);
        isa_data_out : out std_logic_vector(7 downto 0);
        lpt_data     : out std_logic_vector(7 downto 0);
        lpt_status   : in  std_logic_vector(7 downto 3);
        lpt_control  : out std_logic_vector(3 downto 0)
    );
    end component;
    
    signal clock        : std_logic;
    signal isa_reset    : std_logic;
    signal isa_address  : std_logic_vector(9 downto 0);
    signal isa_aen      : std_logic;
    signal isa_ior      : std_logic;
    signal isa_iow      : std_logic;
    signal isa_data_in  : std_logic_vector(7 downto 0);
    signal isa_data_out : std_logic_vector(7 downto 0);
    signal lpt_data     : std_logic_vector(7 downto 0);
    signal lpt_status   : std_logic_vector(7 downto 3);
    signal lpt_control  : std_logic_vector(3 downto 0);

    constant clock_period : time := 10 ns;
begin
    uut:isa_lpt port map (
        clock        => clock,
        isa_reset    => isa_reset,
        isa_address  => isa_address,
        isa_aen      => isa_aen,
        isa_ior      => isa_ior,
        isa_iow      => isa_iow,
        isa_data_in  => isa_data_in,
        isa_data_out => isa_data_out,
        lpt_data     => lpt_data,
        lpt_status   => lpt_status,
        lpt_control  => lpt_control
    );

    clock_process : process begin
        clock <= '0';

        wait for clock_period / 2;

        clock <= '1';

        wait for clock_period / 2;
    end process;

    stim_proc : process begin
        isa_reset <= '0';
        isa_aen   <= '1';

        wait for clock_period * 10;

        isa_aen     <= '0';
        isa_ior     <= '1';
        isa_iow     <= '0';
        isa_address <= "1101111000";
        isa_data_in <= "01001111";

        wait for clock_period * 10;

        isa_address <= "1101111010";
        isa_data_in <= "10100000";

        wait for clock_period * 10;

        isa_reset <= '1';

        wait for clock_period * 10;

        isa_reset   <= '0';
        isa_ior     <= '0';
        isa_iow     <= '1';
        isa_address <= "1101111001";
        lpt_status  <= "01010";

        wait for clock_period * 10;

        lpt_status <= "11111";

        wait for clock_period * 10;

        lpt_status <= "00000";

        wait for clock_period * 10;

        lpt_status <= "10101";

        wait for clock_period * 10;

        isa_reset <= '1';

        wait;
    end process;
end;

