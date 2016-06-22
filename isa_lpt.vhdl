library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity isa_lpt is port (
    clock        : in   std_logic;
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
end;

architecture rtl of isa_lpt is
    signal register_data    : std_logic_vector(7 downto 0);
    signal register_status  : std_logic_vector(7 downto 3);
    signal register_control : std_logic_vector(3 downto 0);
begin
    main_process : process(clock) begin
        lpt_data        <= register_data;
        register_status <= not lpt_status;
        lpt_control(0)  <= not register_control(0);
        lpt_control(1)  <= not register_control(1);
        lpt_control(2)  <=     register_control(2);
        lpt_control(3)  <= not register_control(3);
        
        if isa_reset = '0' then
            if isa_aen = '0' then
                if isa_ior = '0' and isa_iow = '1' then
                    case isa_address is
                        when "1101111001" =>
                            isa_data_out <= register_status & "000";
                        when others =>
                            isa_data_out <= (others => 'U');
                    end case;
                elsif isa_ior = '1' and isa_iow = '0' then
                    case isa_address is
                        when "1101111000" =>
                            register_data <= isa_data_in;
                        when "1101111010" =>
                           register_control <= isa_data_in(7 downto 4);
                        when others =>
                            null;
                    end case;
                end if;
            end if;
        else
            isa_data_out     <= (others => 'U');
            register_data    <= (others => 'U');
            register_status  <= (others => 'U');
            register_control <= (others => 'U');
        end if;
    end process;
end rtl;

